<?php

return function($module_name) {
	$doc = napcdoc::site_getDocumentation();

	foreach ($doc["modules"] as $name => $definitions) {
		if ($module_name === $name) {
			return $definitions;
		}
	}

	return false;
};
