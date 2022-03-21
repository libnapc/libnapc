<?php

/**
 * Returns the version string that will be embedded
 * in library.properties, napc_version() and
 * the documentation site
 */

return function() {
	$git_branch = trim(exec("git rev-parse --abbrev-ref HEAD"));

	if (in_array($git_branch, ["nightly", "dev"])) {
		return trim(exec("git rev-parse HEAD"));
	}

	// todo: get version from git
	return "1.2.0-beta";
};
