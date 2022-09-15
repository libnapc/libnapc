<?php

return function($module_name) {
	$keys = [];

	$keys["left-navigation"] = napcdoc::leftnav_getDefinitionsOfModule(
		$module_name, ""
	);

	$keys["content"] = "<h1>$module_name</h1>";

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

	return $keys;
};