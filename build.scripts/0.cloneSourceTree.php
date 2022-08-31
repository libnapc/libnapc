<?php

return function($preprocess) {
	$entries = napphp::fs_scandirRecursive("src");

	$directories = napphp::arr_filter($entries, function($entry) {
		return $entry["type"] === "directory";
	});

	fwrite(STDERR, "Copying source tree ... ");

	foreach ($directories as $directory) {
		$directory = $directory["relative_path"];

		fwrite(STDERR, "Creating '$directory'\n");

		napphp::fs_mkdir("build/$directory");
	}

	napphp::fs_mkdir("build/__tests__");

	foreach ($entries as $entry) {
		if ($entry["type"] !== "file") continue;

		$file_contents = napphp::fs_readFileString($entry["path"]);

		if (is_callable($preprocess)) {
			$file_contents = $preprocess($file_contents, $entry["basename"]);
		}

		napphp::fs_writeFileStringAtomic("build/".$entry["relative_path"], $file_contents);

		fwrite(STDERR, "Copied '".$entry["relative_path"]."'\n");
	}

	fwrite(STDERR, "done\n");
	exit();
};
