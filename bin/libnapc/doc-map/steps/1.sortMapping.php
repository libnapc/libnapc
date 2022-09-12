<?php

return function($args, &$context) {
	foreach ($context["output"]["modules"] as $module_name => &$definition_list) {
		$definition_list_functions = napphp::arr_filter($definition_list, function($item) {
			return napphp::str_startsWith($item, "f:");
		});

		$definition_list_types = napphp::arr_filter($definition_list, function($item) {
			return napphp::str_startsWith($item, "t:");
		});

		$definition_list = [
			...$definition_list_functions,
			...$definition_list_types
		];
	}

	uksort($context["output"]["modules"], function($a, $b) {
		if ($a === "Core" || $b === "Core") return 100000;

		return strnatcmp($a, $b);
	});
};
