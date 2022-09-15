<?php

(function() {
	$NAPPHP_LOAD_PATH = getenv("NAPPHP_LOAD_PATH");

	if (!strlen($NAPPHP_LOAD_PATH)) {
		throw new Exception("Environment variable 'NAPPHP_LOAD_PATH' not set.");
	}
	else if (!is_file($NAPPHP_LOAD_PATH)) {
		throw new Exception("Could not find '$NAPPHP_LOAD_PATH' (invalid NAPPHP_LOAD_PATH).");
	}

	if (defined("STDERR")) {
		fwrite(STDERR, "NAPPHP_LOAD_PATH=$NAPPHP_LOAD_PATH\n");
	}

	// Only load napphp if not already loaded
	if (!class_exists("napphp")) {
		require_once $NAPPHP_LOAD_PATH;

		if (defined("STDERR")) {
			fwrite(STDERR, "Loaded nap-software/napphp version v".napphp::info_getVersion()."\n");
		}

		// setup tmp_dir
		napphp::set("tmp_dir", __DIR__."/tmp.d/");
	} else {
		if (defined("STDERR")) {
			fwrite(STDERR, "nap-software/napphp already loaded (version=".napphp::info_getVersion().")\n");
		}
	}
})();
