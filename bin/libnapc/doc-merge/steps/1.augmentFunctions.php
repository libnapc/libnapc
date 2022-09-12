<?php

return function($args, &$context) {
	foreach ($context["output"] as $definition_name => &$definition) {
		$c_symbol = $context["c_symbols"][$definition_name];

		if ($c_symbol["kind"] !== "function") continue;

		$doc_block = $context["doc_blocks"][$definition_name];

		$definition["type"] = "fn";
		$definition["params"] = $c_symbol["info"]["params"];

		foreach ($definition["params"] as $param_position => &$definition_param) {
			$parameter_description = libnapc_docMerge_getDescriptionByName(
				"param", $doc_block, $definition_param["name"]
			);

			$definition_param["description"] = $parameter_description;
		}

		$return_description = "";

		if (napphp::arr_keyExists($doc_block, "@return")) {
			$return_description = $doc_block["@return"];
		}

		$definition["return"] = [
			"type" => $c_symbol["info"]["return_type"],
			"description" => $return_description
		];
	}
};
