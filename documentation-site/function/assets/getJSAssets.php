<?php

return function() {
	$js_files = napcdoc::scandirRecursive(__DIR__."/../../assets/js");
	$ret = [];

	foreach ($js_files as $js_file) {
		list($abs_path, $path, $file_name) = $js_file;

		if (substr($file_name, 0, 1) === ".") continue;

		if (substr($file_name, -3, 3) !== ".js") continue;
		if ($file_name === "__init.js") continue;

		$ret[$path] = file_get_contents($abs_path);
	}

	return $ret;
};
