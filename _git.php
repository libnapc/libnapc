<?php

return function() {
	if (strlen(getenv("NAPCDOC_GIT_BRANCH"))) {
		$git_branch = getenv("NAPCDOC_GIT_BRANCH");
	} else {
		$git_branch = trim(exec("git rev-parse --abbrev-ref HEAD"));
	}

	$git_head = trim(exec("git rev-parse HEAD"));

	$release_version = "unknown";

	if ($git_branch === "main") {
		$tmp = trim(exec("git describe --tags"));

		if (substr($tmp, 0, 1) === "v") {
			$release_version = substr($tmp, 1);
		}
	} else {
		$release_version = $git_branch."-".substr($git_head, 0, 7);
	}

	$arduino_version = $release_version;

	if ($git_branch !== "main") {
		$arduino_version = "0.0.1";
	}

	return [
		"branch"          => $git_branch,
		"HEAD"            => $git_head,
		"release_version" => $release_version,
		// arduino IDE only accepts semvers
		"arduino_version" => $arduino_version
	];
};
