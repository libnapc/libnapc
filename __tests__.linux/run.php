#!/usr/bin/env php
<?php

require_once __DIR__."/../load-napphp.php";

function compile($input_file) {
	$output_file = napphp::tmp_createFile();

	napphp::shell_execute(
		"gcc", [
			"cwd" => __DIR__,
			"args" => [
				"-Wall", "-Wextra", "-Wpedantic",
				$input_file,
				"-I../build_files/processed_files/",
				"-L../build_files/",
				"-lnapc",
				"-o",
				$output_file
			]
		]
	);

	return $output_file;
}

(function() {
	fwrite(STDERR, "file_root_path\n");

	$file_root_path_bin = compile(__DIR__."/file_root_path.c");

	$test_invocations = [
		[
			"env" => [],
			"cwd_path" => __DIR__,
			"file_contents" => "cwd"
		],

		[
			"env" => [
				"NAPC_FILE_NO_RESOLVE_ROOT_PATH" => 1
			],
			"cwd_path" => ".",
			"file_contents" => "cwd"
		],

		[
			"env" => [
				"NAPC_FILE_ROOT_PATH" => "mockfs/path/subpath"
			],
			"cwd_path" => __DIR__."/mockfs/path/subpath",
			"file_contents" => "nested"
		],

		[
			"env" => [
				"NAPC_FILE_ROOT_PATH" => "mockfs/path/subpath",
				"NAPC_FILE_NO_RESOLVE_ROOT_PATH" => 1
			],
			"cwd_path" => "mockfs/path/subpath",
			"file_contents" => "nested"
		]
	];

	foreach ($test_invocations as $test_invocation) {
		$output_log_file = napphp::tmp_createFile(".log");

		napphp::shell_execute(
			$file_root_path_bin, [
				"cwd" => __DIR__,
				"env" => $test_invocation["env"],
				"stdout" => $output_log_file,
				"stderr" => $output_log_file
			]
		);

		$lines = napphp::fs_file($output_log_file);

		$used_root_path = $contents_of_file = "";

		foreach ($lines as $line) {
			$line = trim($line);

			if (napphp::str_startsWith($line, "HAL_napc_initFileSystem (linux) root path = ")) {
				$used_root_path = substr($line, strlen("HAL_napc_initFileSystem (linux) root path = "));
			} else if (napphp::str_startsWith($line, "contents_of_file:") && !strlen($contents_of_file)) {
				$contents_of_file = substr($line, strlen("contents_of_file:"));
			}
		}

		if ($contents_of_file !== $test_invocation["file_contents"]) {
			fwrite(STDERR, "Contents of file mismatch!\n");
			fwrite(STDERR, "Expected: ".$test_invocation["file_contents"]."\n");
			fwrite(STDERR, "Actual  : $contents_of_file\n");
			exit(1);
		}

		if ($used_root_path !== "'".$test_invocation["cwd_path"]."'") {
			fwrite(STDERR, "Root path mismatch!\n");
			fwrite(STDERR, "Expected: ".$test_invocation["cwd_path"]."\n");
			fwrite(STDERR, "Actual  : $used_root_path\n");
			exit(1);
		}
	}

	fwrite(STDERR, "file_root_path: ok\n");
})();

(function() {
	fwrite(STDERR, "writer_fail_mode\n");

	$writer_fail_mode_bin = compile(__DIR__."/writer_fail_mode.c");
	$output_log_file = napphp::tmp_createFile(".log");

	$exit_code = napphp::shell_execute(
		$writer_fail_mode_bin, [
			"stdout" => $output_log_file,
			"stderr" => $output_log_file,
			"allow_non_zero_exit_code" => true
		]
	);

	$lines = napphp::fs_file($output_log_file);
	$has_crashed = false;

	foreach ($lines as $line) {
		if (strpos($line, "Write operation failed and mode is set to NOFAIL.") !== false) {
			$has_crashed = true;
		}
	}

	if ($exit_code === 0) {
		$has_crashed = false;
	}

	if (!$has_crashed) {
		fwrite(STDERR, "Expected writer_fail_mode to crash!\n");
		exit(1);
	}

	fwrite(STDERR, "writer_fail_mode: ok\n");
})();
