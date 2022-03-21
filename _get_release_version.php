<?php

/**
 * Returns the version string that will be embedded
 * in library.properties, napc_version() and
 * the documentation site
 */

return function() {
	$git = (require __DIR__."/_git.php")();

	if (in_array($git["branch"], ["nightly", "dev"])) {
		return $git["branch"]."-".substr($git["HEAD"], -8, 8);
	}

	return $git["release_version"];
};
