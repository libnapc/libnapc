<?php

return function() {
	$doc = napcdoc::site_getDocumentation();

	$entries = napcdoc::fs_scandirRecursive(__DIR__."/../../assets/svg");
	$svg_images = [];

	foreach ($entries as $entry) {
		if ($entry["type"] !== "file") continue;

		$filename = basename($entry["path"]);

		if (substr($filename, 0, 1) === ".") continue;

		$svg_images[$entry["path"]] = file_get_contents(
			$entry["realpath"]
		);
	}

	$napcdoc = [
		"lib" => (object)[],
		"definitions" => $doc["definitions"],
		"modules_intro" => $doc["modules_intro"],
		"modules" => $doc["modules"],
		"assets" => [
			"svg" => $svg_images
		]
	];

	napcdoc::site_registerJSCode(
		"window.napcdoc = ".json_encode($napcdoc).";"
	);

	napcdoc::site_includeJSFiles();

	napcdoc::site_registerJSCode(
		file_get_contents(__DIR__."/../../assets/js/__init.js")
	);
};
