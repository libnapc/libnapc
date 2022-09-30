<?php

return function($module_name) {
	$keys = [];

	$keys["site_title"] = "$module_name";

	$keys["left-navigation"] = napcdoc::leftnav_getDefinitionsOfModule(
		$module_name, ""
	);

	$keys["content"] = "<h1>About the $module_name module</h1>";

	$modules_intro = napcdoc::site_getDocumentation()["modules_intro"];

	if (array_key_exists($module_name, $modules_intro)) {
		$keys["content"] .= napcdoc::site_renderMarkdown(
			$modules_intro[$module_name]["@description"] ?? ""
		);

		if (array_key_exists("@example", $modules_intro[$module_name])) {
			$keys["content"] .= '<pre class="code hljs">';
			$keys["content"] .= htmlspecialchars($modules_intro[$module_name]["@example"]);
			$keys["content"] .= '</pre>';
		}
	}

	// used for local search
	$keys["content"] .= "<script>window.napcdoc_requested_module_name = \"$module_name\";</script>";

	return $keys;
};
