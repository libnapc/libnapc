<?php

return function($module_name, $request_definition_name = "") {
	$nav = [];

	$nav[] = [
		"icon" => "module_icon/$module_name",
		"label" => "About the $module_name module",
		"href" => napcdoc::site_link("module/$module_name.html#$module_name"),
		"active" => $request_definition_name === "",
		"name" => $module_name
	];

	$definitions = napcdoc::doc_getDefinitionsOfModule($module_name);
	$doc_definitions = napcdoc::site_getDocumentation()["definitions"];

	foreach ($definitions as $definition) {
		$definition_name = substr($definition, 2);

		if (!array_key_exists($definition_name, $doc_definitions)) continue;

		$definition_meta = $doc_definitions[$definition_name];

		if (!array_key_exists("general_info", $definition_meta)) continue;

		$label = napcdoc::site_shortenDefinitionName($definition_name);
		$icon = "type_icon/outline/struct";
		$type = "";

		if (substr($definition, 0, 2) === "f:") {
			$icon = "type_icon/fn";
			$type = "fn";
		} else if (substr($definition, 0, 2) === "t:") {
			if ($definition_meta["kind"] === "struct") {
				$icon = "type_icon/outline/struct";
			} else if ($definition_meta["kind"] === "opaque") {
				$icon = "type_icon/filled/struct";
			} else if ($definition_meta["kind"] === "enum") {
				$icon = "type_icon/outline/enum";
			} else {
				$icon = "type_icon/outline/type";
			}
			$type = "type";
		} else if (substr($definition, 0, 2) === "m:") {
			$icon = "type_icon/outline/macro";
			$type = "macro";
		}

		$deprecated = false;

		if (array_key_exists("deprecated", $definition_meta["general_info"])) {
			$deprecated = true;
		}

		$definition_module = napcdoc::doc_getModuleByDefinitionName($definition_name);

		$nav[] = [
			"icon" => $icon,
			"label" => $label,
			"brief" => $definition_meta["general_info"]["brief"] ?? "",
			"href" => napcdoc::site_link("definition/$definition_module/$definition_name.html#$definition_name"),
			"active" => $definition_name === $request_definition_name,
			"name" => $definition_name,
			"data-attributes" => [
				"definition-type" => $type
			],
			"strikethrough" => $deprecated
		];
	}

	return $nav;
};
