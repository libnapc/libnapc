<?php

return function($definition_name) {
	$doc = napcdoc::site_getDocumentation();

	foreach ($doc["modules"] as $module_name => $definitions) {
		foreach ($definitions as $definition) {
			if (substr($definition, 2) === $definition_name) {
				return $module_name;
			}
		}
	}

	return false;
};
