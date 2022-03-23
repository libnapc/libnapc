<?php

function doc_extractCSymbols_fixType($type) {
	return str_replace("_Bool", "bool", $type);
}

function doc_extractCSymbols_getFunctionReturnType($qual_type) {
	$type = trim(substr($qual_type, 0, strpos($qual_type, "(")));

	return doc_extractCSymbols_fixType($type);
}

return function() {
	mkdir("build/doc", 0777, true);

	XPHPUtils::shell_assertExecCall(
		"clang -Xclang -ast-dump=json -fsyntax-only build/napc.h > build/doc/napc_symbols.json"
	);

	$ast = json_decode(file_get_contents("build/doc/napc_symbols.json"));

	$functions = [];
	$types = [];

	foreach ($ast->inner as $node) {
		if ($node->kind === "FunctionDecl") {
			if (substr($node->name, 0, strlen("napc_")) !== "napc_") continue;

			$functions[$node->name] = [
				"return_type" => doc_extractCSymbols_getFunctionReturnType($node->type->qualType),
				"params" => [],
				"flags" => []
			];

			if (property_exists($node, "inner")) {
				foreach ($node->inner as $inner_node) {
					if ($inner_node->kind === "ParmVarDecl") {
						$functions[$node->name]["params"][] = [
							"type" => doc_extractCSymbols_fixType($inner_node->type->qualType),
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
		}
	}

	file_put_contents(
		"build/doc/symbols.json",
		json_encode([
			"functions" => $functions,
			"types" => $types
		], JSON_PRETTY_PRINT)
	);
};
