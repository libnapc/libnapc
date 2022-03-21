<?php

// rm -f run ; ./build.scripts/build.php ; php build.scripts/create_gcc_command.php ; ./run

chdir(__DIR__."/..");

if (!is_dir("dist/doc")) {
	mkdir("dist/doc", 0777, true);
}

function get_source_ast() {
	$out = tempnam(sys_get_temp_dir(), "napc_");

	exec(
		"clang -Xclang -ast-dump=json -fsyntax-only dist/napc.h > ".escapeshellarg(
			$out
		), $_output, $exit_code
	);

	if ($exit_code !== 0) {
		throw new Error("Failed to execute clang -ast-dump=json");
	}

	$ret = json_decode(
		file_get_contents($out)
	);

	unlink($out);

	return $ret;
}

$ast = get_source_ast();

$functions = [];
$types = [];

function fixType($type) {
	return str_replace("_Bool", "bool", $type);
}

function get_fn_rettype($qual_type) {
	//var_dump(strpos($qual_type, "("));

	$type = trim(substr($qual_type, 0, strpos($qual_type, "(")));

	return fixType($type);
}

foreach ($ast->inner as $node) {
	//var_dump($node->kind);

	if ($node->kind === "FunctionDecl") {
		//var_dump($node->name);

		if (substr($node->name, 0, strlen("napc_")) !== "napc_") continue;

		$functions[$node->name] = [
			"return_type" => get_fn_rettype($node->type->qualType),
			"params" => [],
			"flags" => []
		];

		if (property_exists($node, "inner")) {
			foreach ($node->inner as $inner_node) {
				//var_dump($inner_node->kind);

				if ($inner_node->kind === "ParmVarDecl") {
					//var_dump($inner_node->name);
					//var_dump($inner_node->type->qualType);

					$functions[$node->name]["params"][] = [
						"type" => fixType($inner_node->type->qualType),
						"name" => $inner_node->name
					];
				}
			}
		}

		if (property_exists($node, "variadic") && $node->variadic) {
			$functions[$node->name]["params"][] = [
				"type" => "...",
				"name" => "..."
			];
		}
	} else if ($node->kind === "TypedefDecl") {
		if (substr($node->name, 0, strlen("napc_")) === "napc_") {
			$types[] = $node->name;
		}
	} else if ($node->kind === "RecordDecl") {
		//echo json_encode($node, JSON_PRETTY_PRINT);
	} else {
	//	var_dump($node->kind);
	}
}

file_put_contents(
	"dist/doc/symbols.json",
	json_encode([
		"functions" => $functions,
		"types" => $types
	], JSON_PRETTY_PRINT)
);
