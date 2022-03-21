<?php

return function($module_name, $selected_definition) {
	$module_definitions = napcdoc::documentation_getDefinitionsOfModule($module_name);
	$navigation = [];

	foreach ($module_definitions as $section => $items) {
		$navigation[$section] = [];

		foreach ($items as $definition) {
			$label = $definition["_name"];

			if ($module_name !== "Core" && $section === "functions") {
				// remove napc_* prefix for module functions
				$label = substr(
					$definition["_name"], strlen("napc_$module_name") + 1
				);
			}

			//$definition["type"] === "document" ? $definition["document_title"] : $definition["_name"]

			$second_icon = $second_icon_class = "";
			$is_deprecated = false;

			if (isset($definition["general_info"]["deprecated"]) && $definition["general_info"]["deprecated"]) {
				$is_deprecated = true;
				$second_icon = "trash-can";
				$second_icon_class = "deprecated";
			} else if (in_array("hal", $definition["flags"] ?? [])) {
				$second_icon = "layers-triple";
				$second_icon_class = "hal";
			}

			$navigation[$section][] = [
				"link" => "$module_name/".$definition["_name"].".html#".$definition["_name"],
				"id" => $definition["_name"],
				"label" => $label,
				"brief" => $definition["general_info"]["brief"] ?? "",
				"icon" => napcdoc::documentation_getIconForDefinition($definition["_name"]),
				"second_icon" => $second_icon,
				"second_icon_class" => $second_icon_class,
				"active" => $selected_definition === $definition["_name"],
				"deprecated" => isset($definition["general_info"]["deprecated"]) && $definition["general_info"]["deprecated"],
				"data-attributes" => [
					"definition-type" => $definition["type"]
				]
			];

		}
	}

	return $navigation;
};
