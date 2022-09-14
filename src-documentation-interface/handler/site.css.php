<?php

return function($http_headers) {
	$site_css = [];

	// CSS
	$css_entries = napphp::fs_scandirRecursive(__DIR__."/../assets/css");

	foreach ($css_entries as $entry) {
		if ($entry["type"] !== "file") continue;
		if (!napphp::str_endsWith($entry["basename"], ".css")) continue;

		array_push($site_css, napphp::fs_readFileString($entry["path"]));
	}

	// SASS
	if (napphp::arr_keyExists($http_headers, "x-sass-cache-dir")) {
		$sass_cache_dir = $http_headers["x-sass-cache-dir"];
	} else {
		$sass_cache_dir = napphp::get("tmp_dir")."/sass.cache/";
		napphp::fs_mkdir($sass_cache_dir);
	}

	$sass_bin_path = "";

	// allow for node-sass because dart-sass does not
	// offer an ARM version (yet)
	if (is_file("/usr/local/bin/node-sass")) {
		$sass_bin_path = "/usr/local/bin/node-sass";
	} else if (napphp::str_contains(strtolower(php_uname()), "linux")) {
		$sass_bin_path = __DIR__."/../bin/linux/sass/sass";
	} else {
		$sass_bin_path = __DIR__."/../bin/macos/sass/sass";
	}

	$sass_entries = napphp::fs_scandirRecursive(__DIR__."/../assets/sass");

	foreach ($sass_entries as $file) {
		if ($file["type"] !== "file") continue;
		if (!napphp::str_endsWith($file["basename"], ".sass")) continue;

		$source_modify_time = filemtime($file["path"]);

		$cache_file_path = $sass_cache_dir."/".str_replace("/", "_", $file["relative_path"]).".css";
		$cache_modify_time = is_file($cache_file_path) ? filemtime($cache_file_path) : 0;
		$transpiled_code = "";

		if ($source_modify_time > $cache_modify_time) {
			list($result, $output) = napcdoc::sass_compileFile(
				$sass_bin_path,
				$file["path"]
			);

			if (!$result) {
				$sass_file = $file["relative_path"];

				if (defined("STDERR")) {
					fwrite(STDERR, $output);
				}

				throw new Exception("Failed to compile SASS file '$sass_file'");
			}

			napphp::fs_writeFileStringAtomic($cache_file_path, $output);

			$transpiled_code = $output;
		} else {
			$transpiled_code = napphp::fs_readFileString($cache_file_path);
		}

		array_push($site_css, $transpiled_code);
	}

	return napphp::arr_join($site_css, "\n\n");
};
