<?php

return function() {
	$sass_cache_path = napcdoc::tmp_getPath()."/sass.cache/";

	if (!is_dir($sass_cache_path)) {
		mkdir($sass_cache_path, 0777, true);
		clearstatcache();
	}

	$sass_files = napcdoc::fs_scandirRecursive(__DIR__."/../../assets/sass");

	foreach ($sass_files as $file) {
		if ($file["type"] !== "file") continue;
		if (substr($file["path"], -5, 5) !== ".sass") continue;

		$source_modify_time = filemtime($file["realpath"]);
		$cache_file_path = $sass_cache_path."/".str_replace("/", "_", $file["path"]).".css";
		$cache_modify_time = is_file($cache_file_path) ? filemtime($cache_file_path) : 0;

		if ($source_modify_time > $cache_modify_time) {
			list($result, $output) = napcdoc::sass_compileFile($file["realpath"]);

			if ($result) {
				napcdoc::site_registerCSSCode($output);

				file_put_contents($cache_file_path, $output);
			} else {
				napcdoc::site_registerError($output);
			}
		} else {
			napcdoc::site_registerCSSCode(
				file_get_contents($cache_file_path)
			);
		}
	}
};
