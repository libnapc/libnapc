<?php

return function($args, &$context) {
	foreach ($context["output"] as $definition_name => &$definition) {
		$c_symbol = $context["c_symbols"][$definition_name];

		if ($c_symbol["kind"] !== "enum") continue;

		$doc_block = $context["doc_blocks"][$definition_name];

		$definition["type"] = "type";
		$definition["kind"] = "enum";

		$definition["values"] = [];

		foreach ($c_symbol["info"] as $enum_name => $enum_value) {
			$enum_description = libnapc_docMerge_getDescriptionByName(
				"enum", $doc_block, $enum_name
			);

			array_push($definition["values"], [
				"name" => $enum_name,
				"value" => $enum_value,
				"description" => $enum_description
			]);
		}
	}
};
/*
            "values": [
                {
                    "name": "NAPC_DNS_OPCODE_QUERY",
                    "value": "",
                    "description": "Standard DNS-Query."
                },
                {
*/
