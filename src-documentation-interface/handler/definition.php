<?php

return function($module_name, $definition_name) {
	$keys = [];

	$keys["site_title"] = "$module_name › ".napcdoc::site_shortenDefinitionName($definition_name);

	$keys["left-navigation"] = napcdoc::leftnav_getDefinitionsOfModule(
		$module_name, $definition_name
	);

	$keys["content"] = napcdoc::site_renderTemplateFile(
		"component/definition/index", [
			"definition_name" => $definition_name
		]
	);

	// used for local search
	$keys["content"] .= "<script>window.napcdoc_requested_module_name = \"$module_name\";</script>";

	return $keys;
};
