<?php

return function($args, &$context) {
	foreach ($context["output"] as $definition_name => &$definition) {
		$c_symbol = $context["c_symbols"][$definition_name];

		if ($c_symbol["kind"] !== "macro") continue;

		$doc_block = $context["doc_blocks"][$definition_name];

		$definition["type"] = "macro";

		if (napphp::arr_keyExists($doc_block, "@param")) {
			$params = napphp::util_arrayify($doc_block["@param"]);

			$definition["params"] = [];

			foreach ($params as $param) {
				list(
					$type,
					$name,
					$description
				) = napphp::str_split($param, " ", 3);

				array_push(
					$definition["params"],
					[
						"name" => $name,
						"type" => $type,
						"description" => $description
					]
				);
			}
		}
	}
};
