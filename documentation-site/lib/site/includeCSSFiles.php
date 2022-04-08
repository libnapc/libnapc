<?php

return function() {
	$entries = napcdoc::fs_scandirRecursive(__DIR__."/../../assets/css");

	foreach ($entries as $entry) {
		if ($entry["type"] !== "file") continue;

		$filename = basename($entry["path"]);

		if (substr($filename, 0, 1) === ".") continue;
		if (substr($filename, -4, 4) !== ".css") continue;

		$css_code = file_get_contents($entry["realpath"]);

		napcdoc::site_registerCSSCode($css_code);
	}
};
