<?php

return function() {
	$napc = napphp::fs_readFileJSON("build/doc/napc.no_files.json");

	$files = [
		"libnapc-linux.tar.gz" => "build/lib",
		"libnapc-arduino.zip" => "build/lib",
		"napc.h" => "build"
	];

	$napc["files"] = [];

	foreach ($files as $file => $dir) {
		$napc["files"][$file] = [
			"checksum" => napphp::fs_hashFile("$dir/$file", "sha256"),
			"size" => filesize("$dir/$file")
		];
	}

	napphp::fs_writeFileJSONAtomic(
		"build/doc/napc.json", $napc
	);
};
