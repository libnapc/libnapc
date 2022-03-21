<?php

return function($module_name, $selected_definition) {
	$module_script  = '<script>';
	$module_script .= 'window.napcdoc_requested_module_name = "'.$module_name.'";';
	$module_script .= 'window.napcdoc_requested_definition = "'.($selected_definition ?? "").'";';
	$module_script .= '</script>';

	if ($selected_definition) {
		$definition = napcdoc::documentation_getDefinition($selected_definition);

		return $module_script.napcdoc::renderFile("module_definition", $definition);
	}

	ob_start();

	$napc = napcdoc::documentation_get();

	if (is_file(__DIR__."/../../doc/content/module/$module_name.php")) {
		require __DIR__."/../../doc/content/module/$module_name.php";
	} else if (array_key_exists($module_name, $napc["modules_intro"])) {
		$module_intro = $napc["modules_intro"][$module_name];

		echo $module_intro["@description"];

		if (array_key_exists("@example", $module_intro)) {
			echo '<h2>Example</h1>';
			echo '<pre class="code hljs">';
			echo htmlspecialchars($module_intro["@example"]);
			echo '</pre>';
		}
	} else {
		echo "<i>This module does not have an introductory text yet.<i>";
	}

	return $module_script.ob_get_clean();
};
