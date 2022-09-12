<?php

return function($args, &$context) {
	$clang_ast = $context["clang-ast"];
	$functions = [];

	foreach ($clang_ast as $node) {
		if ($node["kind"] !== "FunctionDecl") continue;
		if (!napphp::arr_keyExists($node, "name")) continue;

		$node_name = $node["name"];

		if (!napphp::str_contains($node_name, "napc")) {
			fwrite(STDOUT, "Skipping '$node_name'\n");

			continue;
		}

		// ignore __runTests functions
		//if (napphp::str_startsWith($node_name, "__runTests")) continue;

		$functions[$node_name] = [
			"return_type" => libnapc_docExtract_getFunctionReturnType($node["type"]["qualType"]),
			"params" => [],
			"flags" => []
		];

		if (napphp::arr_keyExists($node, "inner")) {
			foreach ($node["inner"] as $inner_node) {
				if ($inner_node["kind"] !== "ParmVarDecl") continue;

				$functions[$node_name]["params"][] = [
					"type" => libnapc_docExtract_fixClangCType($inner_node["type"]["qualType"]),
					"name" => $inner_node["name"]
				];
			}
		}

		if (napphp::arr_keyExists($node, "variadic") && $node["variadic"]) {
			$functions[$node_name]["params"][] = [
				"type" => "...",
				"name" => "..."
			];
		}
	}

	$context["functions"] = $functions;
};
