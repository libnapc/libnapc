<?php

return function() {
	$themes = json_decode(file_get_contents(__DIR__."/../../themes.json"), true);

	$css_files = napcdoc::scandirRecursive(__DIR__."/../../assets/css");
	$ret = [];

	foreach ($css_files as $css_file) {
		list($abs_path, $path, $file_name) = $css_file;

		if (substr($file_name, 0, 1) === ".") continue;

		if (substr($file_name, -4, 4) === ".css") {
			$ret[] = file_get_contents($abs_path);
		} else if (substr($file_name, -8, 8) === ".css.php") {
			$tpl_name = substr($file_name, 0, strlen($file_name) - 8);

			$ret[] = napcdoc::renderFile(
				"css/$tpl_name", $themes
			);
		}
	}

	return $ret;
};
