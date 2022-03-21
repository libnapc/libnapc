<?php

$uname = strtolower(php_uname());

// allow for node-sass because dart-sass does not
// offer an ARM version (yet)
if (is_file("/usr/local/bin/node-sass")) {
	define("SASS_BIN", "/usr/local/bin/node-sass");
} else if (strpos($uname, "linux") !== false) {
	define("SASS_BIN", __DIR__."/../../tooling/linux/sass/sass");
} else {
	define("SASS_BIN", __DIR__."/../../tooling/macos/sass/sass");
}

define("SASS_CACHE_DIR", __DIR__."/../../sass.cache/");
define("SASS_USE_CACHE", true);

return function() {
	$sass_files = napcdoc::scandirRecursive(__DIR__."/../../assets/sass");
	$ret = [];

	file_put_contents("/tmp/sass.log", "// start\n");

	clearstatcache();

	foreach ($sass_files as $sass_file) {
		list($abs_path, $path, $file_name) = $sass_file;

		if (substr($file_name, 0, 1) === ".") continue;
		if (substr($file_name, -5, 5) !== ".sass") continue;

		$file_modify_time = filemtime($abs_path);
		$file_cache_path = SASS_CACHE_DIR."/".str_replace("/", "_", $path).".css";
		$cache_modify_time = 0;

		if (is_file($file_cache_path)) {
			$cache_modify_time = filemtime($file_cache_path);
		}

		$rebuild = $file_modify_time > $cache_modify_time;

		if (!SASS_USE_CACHE) {
			$rebuild = true;
		}

		if ($rebuild) {
			exec(
				escapeshellcmd(SASS_BIN)." ".escapeshellarg($abs_path)." 2>>/tmp/sass.log",
				$out,
				$exit_code
			);

			if ($exit_code !== 0) {
			//	exit("$out \n Failed to compile sass file $path");
			}

			$out = implode("\n", $out);

			file_put_contents($file_cache_path.".tmp", $out);
			rename($file_cache_path.".tmp", $file_cache_path);

			$ret[] = $out;
		} else {
			$ret[] = "/** from cache **/".file_get_contents($file_cache_path);
		}
	}

	return $ret;
};
