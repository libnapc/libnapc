<?php

return function($args, &$context) {
	$clang_ast = $context["clang-ast"];
	$context["typedefs"] = [];

	foreach ($clang_ast as $node) {
		if ($node["kind"] !== "TypedefDecl") continue;
		if (!napphp::arr_keyExists($node, "name")) continue;

		$node_name = $node["name"];

		if (!napphp::str_contains($node_name, "napc")) {
			fwrite(STDOUT, "Skipping '$node_name'\n");

			continue;
		}

		if (!napphp::arr_keyExists($node, "type")) {
			throw new CommandError("Found a TypedefDecl node without 'type'.");
		} else if (!napphp::arr_keyExists($node["type"], "qualType")) {
			throw new CommandError("Found a TypedefDecl node without 'type.qualType'.");
		}

		$typedef_new_name = $node_name;
		$typedef_type     = "alias";
		$typedef_original_name = $node["type"]["qualType"];

		if (napphp::str_startsWith($typedef_original_name, "struct ")) {
			$typedef_type = "struct";
			$typedef_original_name = substr($typedef_original_name, strlen("struct "));
		} else if (napphp::str_startsWith($typedef_original_name, "enum ")) {
			$typedef_type = "enum";
			$typedef_original_name = substr($typedef_original_name, strlen("enum "));
		}

		fwrite(STDOUT, "Found typedef '$typedef_new_name' -> '$typedef_original_name' [$typedef_type]\n");

		$context["typedefs"][$typedef_new_name] = [
			"original_name" => $typedef_original_name,
			"typedef_type" => $typedef_type
		];
	}
};
