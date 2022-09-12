<?php

return function($args, &$context) {
	$enum_types = napphp::arr_filter($context["typedefs"], function($typedef) {
		return $typedef["typedef_type"] === "enum";
	});

	$enum_names = napphp::arr_map($enum_types, function($typedef) {
		return $typedef["original_name"];
	});

	$clang_ast = $context["clang-ast"];
	$enums = [];

	foreach ($clang_ast as $node) {
		if ($node["kind"] !== "EnumDecl") continue;
		if (!napphp::arr_keyExists($node, "name")) continue;

		$node_name = $node["name"];

		if (!in_array($node_name, $enum_names)) {
			fwrite(STDOUT, "Skipping 'enum $node_name'\n");

			continue;
		}

		fwrite(STDOUT, "Found 'enum $node_name'\n");

		$enums[$node_name] = [];

		foreach ($node["inner"] as $inner_node) {
			// todo: use cleaner method
			$value = $inner_node["inner"][0]["inner"][0]["value"] ?? false;

			if ($value !== false) {
				$value = (int)$value;
			}

			$inner_node_name = str_pad($inner_node["name"], 30, " ", STR_PAD_RIGHT);

			fwrite(STDOUT, "    $inner_node_name: ".($value === false ? "N/A" : $value)."\n");

			$enums[$node_name][$inner_node["name"]] = $value;
		}
	}

	$context["enums"] = $enums;
};
