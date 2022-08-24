<?php

return function() {
	$libnapc_release_version = getenv("LIBNAPC_RELEASE_VERSION");

	if (substr($libnapc_release_version, 0, 1) === "v") {
		return substr(
			$libnapc_release_version, 1
		);
	}

	$git_branch = XPHPUtils::git_getCurrentBranch();
	$git_HEAD = XPHPUtils::git_getHEADHash();

	return $git_branch."-".substr($git_HEAD, 0, 7);
};
