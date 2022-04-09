<?php

return function() {
	$napc = json_decode(file_get_contents("build/doc/napc.no_files.json"), true);

	$files = [
		"libnapc-aarch64.a" => "build/lib",
		"libnapc-x86_64.a" => "build/lib",
		"libnapc-arduino.zip" => "build/lib",
		"napc.h" => "build"
	];

	$napc["files"] = [];

	foreach ($files as $file => $dir) {
		$napc["files"][$file] = [
			"checksum" => hash_file("sha256", "$dir/$file"),
			"size" => filesize("$dir/$file")
		];
	}

	file_put_contents(
		"build/doc/napc.json", json_encode($napc, JSON_PRETTY_PRINT)
	);
};
