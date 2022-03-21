<?php

return function() {
	$svg_files = napcdoc::scandirRecursive(__DIR__."/../../assets/svg");
	$ret = [];

	foreach ($svg_files as $svg_file) {
		list($abs_path, $path, $file_name) = $svg_file;

		if (substr($file_name, 0, 1) === ".") continue;
		if (substr($file_name, -4, 4) !== ".svg") continue;

		$svg = file_get_contents($abs_path);

		// remove svg headers
		$svg_start = strpos($svg, "<svg");

		if ($svg_start !== false) {
			$svg = substr($svg, $svg_start);
		}

		$ret[$path] = $svg;
	}

	return $ret;
};
