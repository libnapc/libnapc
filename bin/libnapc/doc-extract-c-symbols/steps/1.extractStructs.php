<?php

return function($args, &$context) {
	$struct_types = napphp::arr_filter($context["typedefs"], function($typedef) {
		return $typedef["typedef_type"] === "struct";
	});

	$struct_names = napphp::arr_map($struct_types, function($typedef) {
		return $typedef["original_name"];
	});

	$clang_ast = $context["clang-ast"];
	$structs = [];

	foreach ($clang_ast as $node) {
		if ($node["kind"] !== "RecordDecl") continue;
		if (!napphp::arr_keyExists($node, "name")) continue;

		$node_name = $node["name"];

		if (!in_array($node_name, $struct_names)) {
			fwrite(STDOUT, "Skipping 'struct $node_name'\n");

			continue;
		}

		fwrite(STDOUT, "Found 'struct $node_name'\n");

		$structs[$node_name] = [];

		foreach ($node["inner"] as $inner_node) {
			$inner_node_name = str_pad($inner_node["name"], 30, " ", STR_PAD_RIGHT);
			$inner_node_type = libnapc_docExtract_fixClangCType($inner_node["type"]["qualType"]);

			if (!is_array($inner_node_type)) {
				fwrite(STDOUT, "    $inner_node_name: $inner_node_type\n");
			} else {
				$inner_node_name = str_pad($inner_node["name"]."[".$inner_node_type[1]."]", 30, " ", STR_PAD_RIGHT);

				fwrite(STDOUT, "    $inner_node_name: ".$inner_node_type[0]."\n");
			}

			$structs[$node_name][$inner_node["name"]] = $inner_node_type;
		}
	}

	$context["structs"] = $structs;
};
