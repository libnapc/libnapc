<?php

return function($args, &$context) {
	$output = &$context["output"];
	$statistics = &$output["statistics"];

	$statistics["fn_missing_origins"] = 0;

	foreach ($output["definitions"] as $definition_name => &$definition) {
		if ($definition["type"] !== "fn") continue;

		$fn_colored = napphp::terminal_colorString($definition_name, "yellow");

		$return_type = napphp::str_replace(
			$definition["return"]["type"], "*", "\*"
		);

		$search_expression = "";

		// do not add space for pointer return types
		if (napphp::str_endsWith($return_type, "*")) {
			$search_expression = "$return_type$definition_name(";
		} else {
			$search_expression = "$return_type $definition_name(";
		}

		$origin = libnapc_docFinalize_searchWithGrep(
			$search_expression, ".c"
		);

		if ($origin === NULL) {
			fwrite(STDERR, "Was not able to determine origin of function '$fn_colored'.\n");

			$statistics["fn_missing_origins"]++;

			continue;
		}

		$definition["origin"] = $origin;
	}
};
