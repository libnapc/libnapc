<?php

return function($args, &$context) {
	$output = &$context["output"];
	$statistics = &$output["statistics"];

	$statistics["macro_missing_origins"] = 0;

	foreach ($output["definitions"] as $definition_name => &$definition) {
		if ($definition["type"] !== "macro") continue;

		$macro_colored = napphp::terminal_colorString($definition_name, "yellow");

		$search_expression = "#define $definition_name";

		$origin = libnapc_docFinalize_searchWithGrep(
			$search_expression, ".h"
		);

		if ($origin === NULL) {
			fwrite(STDERR, "Was not able to determine origin of macro '$macro_colored'.\n");

			$statistics["macro_missing_origins"]++;

			continue;
		}

		$definition["origin"] = $origin;
	}
};
