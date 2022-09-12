<?php

return function($args, &$context) {
	$modules = [];

	foreach ($context["output"]["definitions"] as $definition_name => $definition) {
		if (!napphp::arr_keyExists($definition, "type")) {
			throw new CommandError(
				"Definition '$definition_name' does not have a 'type'!"
			);
		}

		$module_name = $definition["_associated_module"];

		if (!napphp::arr_keyExists($modules, $module_name)) {
			$modules[$module_name] = [];
		}

		if ($definition["type"] === "fn") {
			$definition_str = "f:".$definition["name"];
		} else if ($definition["type"] === "type") {
			$definition_str = "t:".$definition["name"];
		}

		array_push(
			$modules[$module_name], $definition_str
		);
	}

	$context["output"]["modules"] = $modules;
};
