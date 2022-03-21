<?php

/**
 * Returns the version string that will be embedded
 * in library.properties, napc_version() and
 * the documentation site
 */

return function() {
	$git = (require __DIR__."/_git.php")();

	return $git["release_version"];
};
