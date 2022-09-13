#!/usr/bin/env php
<?php

chdir(__DIR__);

// todo: check php version
$NAPPHP_LOAD_PATH = getenv("NAPPHP_LOAD_PATH");

if (!is_file($NAPPHP_LOAD_PATH)) {
	fwrite(STDERR, "Either NAPPHP_LOAD_PATH is not set, or does not exist.\n");
	exit(2);
}

require_once $NAPPHP_LOAD_PATH;

fwrite(STDERR, "[debug] Using napphp version v".napphp::info_getVersion()."\n");

napphp::set("tmp_dir", __DIR__."/../tmp.d/");




function compile($test) {
	$output_file = napphp::tmp_createFile();

	napphp::shell_execTransparently(
		"gcc", [
			"-Wall", "-Wextra", "-Wpedantic",
			"$test.c",
			"-I../build_files/processed_files/",
			"-L../build_files/",
			"-lnapc",
			"-o",
			$output_file
		]
	);

	return $output_file;
}

$file_root_path_bin = compile("file_root_path");

function file_root_path($env = "") {
	global $file_root_path_bin;

	$used_root_path = "";
	$contents_of_file = "";

	$lines = napphp::proc_exec("$env ".escapeshellcmd($file_root_path_bin)." 2>&1");

	foreach ($lines as $line) {
		if (napphp::str_startsWith($line, "HAL_napc_initFileSystem (linux) root path = ")) {
			$used_root_path = substr($line, strlen("HAL_napc_initFileSystem (linux) root path = "));
		} else if (napphp::str_startsWith($line, "contents_of_file:") && !strlen($contents_of_file)) {
			$contents_of_file = substr($line, strlen("contents_of_file:"));
		}
	}

	return [
		substr($used_root_path, 1, -1), $contents_of_file
	];
}

$tests = [
	// root_path = CWD
	[
		file_root_path(), __DIR__, "cwd"
	],
	[
		file_root_path("NAPC_FILE_NO_RESOLVE_ROOT_PATH=1"), ".", "cwd"
	],
	// root_path = mock
	[
		file_root_path("NAPC_FILE_ROOT_PATH=mockfs/path/subpath"), __DIR__."/mockfs/path/subpath", "nested"
	],
	[
		file_root_path("NAPC_FILE_ROOT_PATH=mockfs/path/subpath NAPC_FILE_NO_RESOLVE_ROOT_PATH=1"), "mockfs/path/subpath", "nested"
	]
];

foreach ($tests as $test) {
	list($result, $expected_root_path, $expected_file_contents) = $test;

	if ($result[0] !== $expected_root_path) {
		fwrite(STDERR, "Unexpected root path: ".$result[0]."\n");
		exit(1);
	} else if ($result[1] !== $expected_file_contents) {
		fwrite(STDERR, "Unexpected file_contents: ".$result[1]."\n");
		exit(1);
	} else {
		echo "pass\n";
	}
}

$write_fail_mode_bin = compile("writer_fail_mode");

function writer_fail_mode() {
	global $write_fail_mode_bin;

	$has_crashed = false;

	exec(escapeshellcmd($write_fail_mode_bin)." 2>&1", $lines, $exit_code);

	foreach ($lines as $line) {
		if (strpos($line, "Write operation failed and no_fail_mode is set to true") !== false) {
			$has_crashed = true;
		}
	}

	if ($exit_code === 0) {
		$has_crashed = false;
	}

	return $has_crashed;
}

if (!writer_fail_mode()) {
	fwrite(STDERR, "Expected program to crash\n");
	exit(1);
} else {
	echo "pass\n";
}
