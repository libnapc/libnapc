<?php

function doc_extractCSymbols_fixType($type) {
	return str_replace("_Bool", "bool", $type);
}

function doc_extractCSymbols_getFunctionReturnType($qual_type) {
	$type = trim(substr($qual_type, 0, strpos($qual_type, "(")));

	return doc_extractCSymbols_fixType($type);
}

return function() {
	napphp::fs_mkdir("build/doc");

	napphp::shell_execTransparently(
		"clang -Xclang -ast-dump=json -fsyntax-only build/napc.h > build/doc/napc_symbols.json"
	);

	$ast = napphp::fs_readFileJSON("build/doc/napc_symbols.json", false);

	$functions = [];
	$types = [];

	foreach ($ast->inner as $node) {
		if ($node->kind === "FunctionDecl") {
			if (!napphp::str_startsWith($node->name, "napc_")) continue;
			// ignore __runTests functions
			if (napphp::str_startsWith($node->name, "__runTests")) continue;

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

	napphp::fs_writeFileJSONAtomic(
		"build/doc/symbols.json",
		[
			"functions" => $functions,
			"types" => $types
		]
	);
};
