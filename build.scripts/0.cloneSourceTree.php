<?php

return function($preprocess) {
	$entries = XPHPUtils::fs_scandirRecursive("src");

	$directories = array_filter($entries, function($entry) {
		return $entry["type"] === "dir";
	});

	fwrite(STDERR, "Copying source tree ... ");

	foreach ($directories as $directory) {
		$directory = $directory["rel_path"];

		if (is_dir("build/$directory")) continue;

		mkdir("build/$directory", 0777, true);
	}

	mkdir("build/__tests__");

	foreach ($entries as $entry) {
		if ($entry["type"] !== "file") continue;

		$file_contents = file_get_contents($entry["abs_path"]);
		$dest_path = "build/".$entry["rel_path"];

		if (is_callable($preprocess)) {
			$file_contents = $preprocess($file_contents, $entry["basename"]);
		}

		file_put_contents($dest_path.".tmp", $file_contents);
		rename($dest_path.".tmp", $dest_path);

		fwrite(STDERR, "Copied ".$entry["rel_path"]." \n");
	}

	fwrite(STDERR, "done\n");
};
