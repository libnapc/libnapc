<?php

return function($definition_name) {
	$napc = napcdoc::documentation_get();

	foreach ($napc["modules"] as $module_name => $module_definitions) {
		foreach ($module_definitions as $module_definition) {
			if (substr($module_definition, 2) === $definition_name) {
				return $module_name;
			}
		}
	}

	throw new Exception("Unable to find module of '$definition_name'");
};
