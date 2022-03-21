<?php

return function() {
	$css_files = napcdoc::scandirRecursive(__DIR__."/../../assets/css");
	$ret = [];

	foreach ($css_files as $css_file) {
		list($abs_path, $path, $file_name) = $css_file;

		if (substr($file_name, 0, 1) === ".") continue;

		if (substr($file_name, -4, 4) === ".css") {
			$ret[] = file_get_contents($abs_path);
		}
	}

	return $ret;
};
