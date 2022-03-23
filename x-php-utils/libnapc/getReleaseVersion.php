<?php

return function() {
	$git_branch = XPHPUtils::git_getCurrentBranch();
	$git_HEAD = XPHPUtils::git_getHEADHash();

	$release_version = $git_branch."-".substr($git_HEAD, 0, 7);

	if ($git_branch === "main") {
		$tmp = trim(exec("git describe --tags"));

		if (substr($tmp, 0, 1) === "v") {
			$release_version = substr($tmp, 1);
		}
	}

	return $release_version;
};
