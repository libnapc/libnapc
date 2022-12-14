<?php

/**
 * Convert module name $module_name into a C-friendly identifier
 */
function libnapc_preprocess_CFriendlyModuleName($module_name) {
	return napphp::str_replace($module_name, "-", "");
}

return [
	"description" => [
		"Preprocess source files. This does: ",
		"",
		"  - replace all %BC_*% values with their respective value.",
		"  - inline all local header includes in src/libnapc.h.",
		"  - generate boot_functions.c file from .boot files.",
		"  - generate valid C source files for tests (__tests__) (this is skipped with --no-tests)."
	],

	"depends_on" => [],
	"creates"    => ["processed_files", "build_constants.json"],

	"run" => function($args) {
		$temp_dir = napphp::tmp_createDirectory();

		$release_version = libnapc_getReleaseVersion();

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
