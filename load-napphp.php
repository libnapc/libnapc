<?php

(function() {
	$getPathOfDependency = require __DIR__."/.dependencies/getPath.php";

	// Only load napphp if not already loaded
	if (!class_exists("napphp")) {
		require_once $getPathOfDependency("napphp")."/src/index.php";

		if (defined("STDERR")) {
			fwrite(STDERR, "Loaded nap-software/napphp version v".napphp::info_getVersion()."\n");
			fwrite(STDERR, "Using PHP v".phpversion()."\n");
		}
	} else {
		if (defined("STDERR")) {
			fwrite(STDERR, "nap-software/napphp already loaded (version=".napphp::info_getVersion().")\n");
		}
	}
})();
