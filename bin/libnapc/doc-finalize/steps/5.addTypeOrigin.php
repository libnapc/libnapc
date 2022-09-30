<?php

return function($args, &$context) {
	$output = &$context["output"];
	$statistics = &$output["statistics"];

	$statistics["type_missing_origins"] = 0;

	foreach ($output["definitions"] as $definition_name => &$definition) {
		if ($definition["type"] !== "type") continue;
		if (!in_array($definition["kind"], ["alias", "struct"])) continue;

		$type_colored = napphp::terminal_colorString($definition_name, "yellow");

		$search_expression = "";

		// search for 'typedef [PLACEHOLDER] $definition_name;' if kind is alias
		if ($definition["kind"] === "alias") {
			$search_expression = "typedef [A-Za-z_0-9 ]\+ $definition_name;";
		}
		// search for 'typedef struct $definition_name' if kind is struct
		else {
			$search_expression = "typedef struct $definition_name {";
		}

		$origin = libnapc_docFinalize_searchWithGrep(
			$search_expression, ".h"
		);

		if ($origin === NULL) {
			fwrite(STDERR, "Was not able to determine origin of type '$type_colored'.\n");

			$statistics["type_missing_origins"]++;

			continue;
		}

		$definition["origin"] = $origin;
	}
};
