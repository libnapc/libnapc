<?php

return function($args, &$context) {
	foreach ($context["output"] as $definition_name => &$definition) {
		$c_symbol = $context["c_symbols"][$definition_name];

		if ($c_symbol["kind"] !== "struct") continue;

		$doc_block = $context["doc_blocks"][$definition_name];

		$definition["type"] = "type";

		if (!napphp::arr_keyExists($doc_block, "@opaque")) {
			$definition["kind"] = "struct";

			$definition["fields"] = [];

			foreach ($c_symbol["info"] as $field_name => $field_type) {
				$field_description = libnapc_docMerge_getDescriptionByName(
					"field", $doc_block, $field_name
				);

				array_push($definition["fields"], [
					"name" => $field_name,
					"type" => $field_type,
					"description" => $field_description
				]);
			}
		} else {
			$definition["kind"] = "opaque";
		}
	}
};
