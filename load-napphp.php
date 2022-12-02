<?php

(function() {
	$getPathOfDependency = require __DIR__."/.dependencies/getPath.php";

	// Only load napphp if not already loaded
	if (!class_exists("napphp")) {
		require_once $getPathOfDependency("napphp")."/src/__loadAsClass.php";

		if (defined("STDERR")) {
			fwrite(STDERR, "Loaded nap-software/napphp version v".napphp::info_getVersion()."\n");
			fwrite(STDERR, "Using PHP v".phpversion()."\n");
		}

		// setup tmp_dir
		napphp::set("tmp_dir", __DIR__."/tmp.d/");
		napphp::set("terminate_on_warning", true);
		napphp::set("warning_print_trace", true);
	} else {
		if (defined("STDERR")) {
			fwrite(STDERR, "nap-software/napphp already loaded (version=".napphp::info_getVersion().")\n");
		}
	}
})();
