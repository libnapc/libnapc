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
		if (strpos($line, "Write operation failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC.") !== false) {
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


(function() {
	fwrite(STDERR, "reader_fail_mode\n");

	$writer_fail_mode_bin = compile(__DIR__."/reader_fail_mode.c");
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
		if (strpos($line, "Read operation failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC.") !== false) {
			$has_crashed = true;
		}
	}

	if ($exit_code === 0) {
		$has_crashed = false;
	}

	if (!$has_crashed) {
		fwrite(STDERR, "Expected reader_fail_mode to crash!\n");
		exit(1);
	}

	fwrite(STDERR, "reader_fail_mode: ok\n");
})();

(function() {
	fwrite(STDERR, "ring-buffer_fail_mode\n");

	$writer_fail_mode_bin = compile(__DIR__."/ring-buffer_fail_mode.c");
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
		if (strpos($line, "Insert operation (WRITE_BYTE) failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC.") !== false) {
			$has_crashed = true;
		}
	}

	if ($exit_code === 0) {
		$has_crashed = false;
	}

	if (!$has_crashed) {
		fwrite(STDERR, "Expected ring-buffer_fail_mode to crash!\n");
		exit(1);
	}

	fwrite(STDERR, "ring-buffer_fail_mode: ok\n");
})();
