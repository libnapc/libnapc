<?php

return function() {
	$site_js = [];

	$doc = napcdoc::site_getDocumentation();

	$svg_entries = napphp::fs_scandirRecursive(__DIR__."/../assets/svg");
	$svg_images = [];

	foreach ($svg_entries as $entry) {
		if ($entry["type"] !== "file") continue;
		if (!napphp::str_endsWith($entry["basename"], ".svg")) continue;

		$svg_images[$entry["relative_path"]] = napphp::fs_readFileString($entry["path"]);
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

	array_push($site_js, "window.napcdoc = ".json_encode($napcdoc).";");

	$js_entries = napphp::fs_scandirRecursive(__DIR__."/../assets/js");

	foreach ($js_entries as $entry) {
		if ($entry["type"] !== "file") continue;
		if (!napphp::str_endsWith($entry["basename"], ".js")) continue;
		if ($entry["basename"] === "__init.js") continue;

		$js_file_code = napphp::fs_readFileString($entry["path"]);
		$filename = $entry["relative_path"];

		$js_code = <<<JS_CODE
(function() {
	try {
		$js_file_code
		console.log("Loaded file '$filename'");
	} catch (e) {
		console.error("Error in file '$filename'", e);
	}
})();
JS_CODE;

		array_push($site_js, $js_code);
	}

	array_push($site_js, napphp::fs_readFileString(__DIR__."/../assets/js/__init.js"));

	return napphp::arr_join($site_js, "\n\n");
};
