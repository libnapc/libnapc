<?php

return function($module_name, $definition_name) {
	$keys = [];

	$keys["left-navigation"] = napcdoc::leftnav_getDefinitionsOfModule(
		$module_name, $definition_name
	);

	$keys["content"] = napcdoc::site_renderTemplateFile(
		"component/definition/index", [
				"definition_name" => $definition_name
		]
	);

	return $keys;
};
