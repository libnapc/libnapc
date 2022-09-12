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

return [
	"description" => [
		"Preprocess source files. This does: ",
		"",
		"  - replace all %BC_*% values with their respective value.",
		"  - inline all local header includes in src/napc.h.",
		"  - generate boot_functions.c file from .boot files.",
		"  - generate valid C source files for tests (__tests__) (this is skipped with --no-tests)."
	],

	"depends_on" => [],
	"creates"    => "processed_files",

	"run" => function($args) {
		$temp_dir = napphp::tmp_createDirectory();

		$release_version = libnapc_preprocess_getReleaseVersion();

		$build_constants = [
			"GIT_HEAD_HASH" => napphp::git_getHEADSha1Hash(),
			"RELEASE_VERSION" => $release_version,
			"ARDUINO_LIBRARY_NAME" => "libnapc",
			"ARDUINO_LIBRARY_VERSION" => $release_version,
			"ARDUINO_LIBRARY_URL" => "https://libnapc.nap-software.com/",
			"BUILD_DATE" => ""
		];

		$context = [
			"output_dir" => $temp_dir,
			"build_constants" => $build_constants
		];

		command_runSteps("preprocess", $args, $context);

		napphp::fs_writeFileJSONAtomic(
			LIBNAPC_BUILD_FILES_DIR."/build_constants.json",
			$build_constants,
			true
		);

		napphp::fs_rename(
			$temp_dir, LIBNAPC_BUILD_FILES_DIR."/processed_files/"
		);
	}
];
