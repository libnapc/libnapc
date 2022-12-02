<?php

return function($dependency_name) {
	static $exists = NULL;

	if (!$exists) {
		$exists = function($path) {
			return is_file($path) || is_link($path);
		};
	}

	$custom_dependency_path = __DIR__."/custom/$dependency_name";

	if ($exists($custom_dependency_path)) {
		return $custom_dependency_path;
	}

	return __DIR__."/default/$dependency_name";
};
