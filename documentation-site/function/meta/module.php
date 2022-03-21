<?php

return function($module_name, $selected_definition) {
	if ($selected_definition) {
		$definition = napcdoc::documentation_getDefinition($selected_definition);

		return [
			"title" => $selected_definition,
			"site_name" => "libnapc",
			"description" => $definition["general_info"]["brief"] ?? ""
		];
	}

	return [
		"title" => $module_name,
		"site_name" => "libnapc",
		"description" => ""
	];
};
