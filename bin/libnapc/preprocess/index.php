<?php

function libnapc_preprocess_getReleaseVersion() {
	$libnapc_release_version = getenv("LIBNAPC_RELEASE_VERSION");

	if (napphp::str_startsWith($libnapc_release_version, "v")) {
		return substr(
			$libnapc_release_version, 1
		);
	}

	$git_branch = napphp::git_getCurrentBranch();
	$git_HEAD = napphp::git_getHEADSha1Hash();

	return $git_branch."-".substr($git_HEAD, 0, 7);
}

return function($args) {
	if (napphp::fs_isDirectory(LIBNAPC_BUILD_FILES_DIR."/processed_files/")) {
		throw new CommandError(
			"Files already preprocessed. Use 'libnapc clean' to remove them."
		);
	}

	$temp_dir = napphp::tmp_createDirectory();

	$release_version = libnapc_preprocess_getReleaseVersion();

	$build_constants = [
		"GIT_HEAD_HASH" => napphp::git_getHEADSha1Hash(),
		"RELEASE_VERSION" => $release_version,
		"ARDUINO_LIBRARY_NAME" => "libnapc",
		"ARDUINO_LIBRARY_VERSION" => $release_version,
		"ARDUINO_LIBRARY_URL" => "https://libnapc.nap-software.com/",
		"BUILD_DATE" => BUILD_DATE
	];

	libnapc_run_steps("preprocess", $args, [
		"output_dir" => $temp_dir,
		"build_constants" => $build_constants
	]);

	napphp::fs_writeFileJSONAtomic(
		LIBNAPC_BUILD_FILES_DIR."/build_constants.json",
		$build_constants,
		true
	);

	napphp::fs_rename(
		$temp_dir, LIBNAPC_BUILD_FILES_DIR."/processed_files/"
	);
};
