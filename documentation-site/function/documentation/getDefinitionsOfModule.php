<?php

return function($module_name) {
	$napc = napcdoc::documentation_get();

	$module_definitions = $napc["modules"][$module_name];
	$napc_definitions = $napc["definitions"];

	$module = [
	//	"documents" => [],
		"functions" => [],
		"macros" => [],
		"types" => []
	];

	foreach ($module_definitions as $_definition) {
		$definition_name = substr($_definition, 2);

		if (!array_key_exists($definition_name, $napc_definitions)) continue;

		$definition = $napc_definitions[$definition_name];
		$definition["_name"] = $definition_name;

		// ignore undocumented definitions
		if (!array_key_exists("general_info", $definition)) continue;

		switch ($definition["type"]) {
			case "document":
			//	$module["documents"][] = $definition;
			break;

			case "fn":
				$module["functions"][] = $definition;
			break;

			case "macro":
				$module["macros"][] = $definition;
			break;

			case "type":
				$module["types"][] = $definition;
			break;
		}
	}

	return $module;
};
