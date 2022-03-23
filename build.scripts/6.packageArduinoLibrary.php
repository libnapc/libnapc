<?php

return function() {
	$entries = XPHPUtils::fs_scandirRecursive("build");

	$directories = array_filter($entries, function($entry) {
		return $entry["type"] === "dir";
	});

	foreach ($directories as $directory) {
		$directory = $directory["rel_path"];

		if (is_dir("build/arduino_files/src/$directory")) continue;

		mkdir("build/arduino_files/src/$directory", 0777, true);
	}

	$source_files = array_filter($entries, function($entry) {
		if ($entry["type"] !== "file") return false;

		if (substr($entry["basename"], -2, 2) === ".c") return true;
		if (substr($entry["basename"], -2, 2) === ".h") return true;
		if (substr($entry["basename"], -4, 4) === ".hpp") return true;

		return substr($entry["basename"], -4, 4) === ".cpp";
	});

	mkdir("build/arduino_files/src", 0777, true);

	foreach ($source_files as $source_file) {
		$dest_path = "build/arduino_files/src/".$source_file["rel_path"];

		copy($source_file["abs_path"], $dest_path);
	}

	copy("build/library.properties", "build/arduino_files/library.properties");
	copy("LICENSE", "build/arduino_files/LICENSE");
	copy("README.md", "build/arduino_files/README.md");

	foreach (scandir("arduino_examples") as $example) {
		mkdir("build/arduino_files/examples/$example", 0777, true);

		copy(
			"arduino_examples/$example/$example.ino",
			"build/arduino_files/examples/$example/$example.ino",
		);
	}

	XPHPUtils::shell_assertSystemCall(
		"cd build/arduino_files/ && zip -r ../lib/libnapc-arduino.zip ."
	);
};
