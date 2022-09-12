<?php

return function($args, &$context) {
	foreach ($context["output"] as $definition_name => &$definition) {
		$c_symbol = $context["c_symbols"][$definition_name];

		if ($c_symbol["kind"] !== "alias") continue;

		$doc_block = $context["doc_blocks"][$definition_name];

		$definition["type"] = "type";
		$definition["kind"] = "alias";

		$definition["alias_of"] = $c_symbol["info"];
	}
};
