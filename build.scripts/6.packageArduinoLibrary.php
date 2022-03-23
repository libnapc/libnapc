<?php

return function() {
	$source_files = XPHPUtils::fs_scandirRecursive("build");

	$source_files = array_filter($source_files, function($entry) {
		if ($entry["type"] !== "file") return false;

		if (substr($entry["basename"], -2, 2) === ".c") return true;
		if (substr($entry["basename"], -2, 2) === ".h") return true;
		if (substr($entry["basename"], -4, 4) === ".hpp") return true;

		return substr($entry["basename"], -4, 4) === ".cpp";
	});

	mkdir("build/arduino_files/src", 0777, true);

	foreach ($source_files as $source_file) {
		$dest_path = "build/arduino_files/src/".str_replace("/", "_", $source_file["rel_path"]);

		copy($source_file["abs_path"], $dest_path);
	}

	copy("build/library.properties", "build/arduino_files/library.properties");
	copy("LICENSE", "build/arduino_files/src/LICENSE");

	XPHPUtils::shell_assertSystemCall(
		"cd build/arduino_files/ && zip -r ../lib/libnapc-arduino.zip ."
	);
};
