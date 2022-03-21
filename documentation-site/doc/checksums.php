<?php

return (function() {
	$ret = [];
	$files = [
		"libnapc.a",
		"libnapc-aarch64.a",
		"napc.h",
		"libnapc-arduino.zip"
	];

	foreach ($files as $file) {
		$file_path = __DIR__."/../../dist/$file";
		$file_hash = "n/a";

		if (is_file($file_path)) {
			$file_hash = hash_file(
				"sha256", __DIR__."/../../dist/$file"
			);
		}

		$ret[$file] = $file_hash;
	}

	return $ret;
})();
