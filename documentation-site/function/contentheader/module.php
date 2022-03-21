<?php

return function($module_name, $selected_definition) {
	if ($selected_definition) {
		$definition = napcdoc::documentation_getDefinition($selected_definition);
		$title = $definition["name"];

		if ($module_name !== "Core" && $definition["type"] === "fn") {
			// remove napc_* prefix for module functions
			$title = substr(
				$definition["name"], strlen("napc_$module_name") + 1
			);
		}

		$is_deprecated = $definition["general_info"]["deprecated"] ?? false;

		$second_icon = $second_icon_class = "";

		if ($is_deprecated) {
			$second_icon = "trash-can";
			$second_icon_class = "deprecated";
		} else if (in_array("hal", $definition["flags"] ?? [])) {
			$second_icon = "layers-triple";
			$second_icon_class = "hal";
		}

		return  [
			"icon" => napcdoc::documentation_getIconForDefinition($definition["name"]),
			"title" => $title,
			"description" => $definition["general_info"]["brief"] ?? "",
			"data-attributes" => [
				"definition-type" => $definition["type"]
			],
			"second_icon" => $second_icon,
			"second_icon_class" => $second_icon_class
		];
	}

	$description = "<i>This module has not a description</i>";

	$napc = napcdoc::documentation_get();

	if (is_file(__DIR__."/../../doc/description/$module_name.php")) {
		$description = require __DIR__."/../../doc/description/$module_name.php";
	} else if (array_key_exists($module_name, $napc["modules_intro"])) {
		$module_intro = $napc["modules_intro"][$module_name];

		if (array_key_exists("@brief", $module_intro)) {
			$description = $module_intro["@brief"];
		}
	}

	return[
		"icon" => "module_icon/$module_name",
		"title" => $module_name,
		"description" => $description
	];
};
