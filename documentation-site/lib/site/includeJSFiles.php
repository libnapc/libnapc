<?php

return function() {
	$entries = napcdoc::fs_scandirRecursive(__DIR__."/../../assets/js");

	foreach ($entries as $entry) {
		if ($entry["type"] !== "file") continue;

		$filename = basename($entry["path"]);

		if (substr($filename, 0, 1) === ".") continue;
		if (substr($filename, -3, 3) !== ".js") continue;

		if ($entry["path"] === "__init.js") continue;

		$js_code = file_get_contents($entry["realpath"]);

		napcdoc::site_registerJSCode(
			"(function() {\n".
			"try{".
			$js_code.
			"console.log(\"Loaded file $filename\");".
			"} catch (e) {\n".
			"console.error(\"Error in file $filename\", e);".
			"}\n".
			"})();\n"
		);
	}
};
