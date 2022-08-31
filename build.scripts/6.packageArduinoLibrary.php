<?php

return function() {
	$entries = napphp::fs_scandirRecursive("build");

	$directories = napphp::arr_filter($entries, function($entry) {
		return $entry["type"] === "directory";
	});

	foreach ($directories as $directory) {
		$directory = $directory["relative_path"];

		napphp::fs_mkdir("build/arduino_files/src/$directory");
	}

	$source_files = napphp::arr_filter($entries, function($entry) {
		if ($entry["type"] !== "file") return false;

		if (napphp::str_endsWith($entry["basename"], ".c")) return true;
		if (napphp::str_endsWith($entry["basename"], ".h")) return true;
		if (napphp::str_endsWith($entry["basename"], ".hpp")) return true;

		return napphp::str_endsWith($entry["basename"], ".cpp");
	});

	foreach ($source_files as $source_file) {
		$dest_path = "build/arduino_files/src/".$source_file["relative_path"];

		napphp::fs_copyFile($source_file["path"], $dest_path);
	}

	napphp::fs_copyFile("build/library.properties", "build/arduino_files/library.properties");
	napphp::fs_copyFile("LICENSE", "build/arduino_files/LICENSE");
	napphp::fs_copyFile("README.md", "build/arduino_files/README.md");

	foreach (napphp::fs_scandir("arduino_examples") as $example) {
		napphp::fs_mkdir("build/arduino_files/examples/$example");

		napphp::fs_copyFile(
			"arduino_examples/$example/$example.ino",
			"build/arduino_files/examples/$example/$example.ino",
		);
	}

	napphp::proc_changeWorkingDirectory("build/arduino_files", function() {
		napphp::shell_execTransparently(
			"zip -r ../lib/libnapc-arduino.zip ."
		);
	});

	exit();
};
