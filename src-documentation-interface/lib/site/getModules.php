<?php

return function() {
	$modules = array_keys(napcdoc::site_getDocumentation()["modules"]);

	return array_values(
		array_filter($modules, function($module) {
			return $module !== "app";
		})
	);
};
