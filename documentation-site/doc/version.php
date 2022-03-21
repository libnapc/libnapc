<?php

return function() {
	if (is_file(__DIR__."/../../_get_release_version.php")) {
		$fn = require __DIR__."/../../_get_release_version.php";

		return $fn();
	}

	return "n/a";
};
