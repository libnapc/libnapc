<?php

return function() {
	$navigation = [];

	$categories = napcdoc::documentation_categorizeModules(
		napcdoc::documentation_get()["modules"]
	);

	foreach ($categories as $category_name => $modules) {
		$navigation[$category_name] = [];

		foreach ($modules as $module_name) {
			$navigation[$category_name][] = [
				"link" => "./$module_name.html",
				"icon" => "module_icon/$module_name",
				"label" => $module_name,
				"id" => $module_name
			];
		}
	}

	return $navigation;
};
