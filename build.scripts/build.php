#!/usr/bin/env php
<?php
require_once __DIR__."/../php.lib/exec_or_die.php";

chdir(__DIR__."/../");

$include_tests = "yes";

if (sizeof($argv) > 1) {
	if ($argv[1] === "--no-tests") {
		$include_tests = "no";
	}
}

exec_or_die("rm -rf dist");
exec_or_die("mkdir dist");
exec_or_die("php build.scripts/create_boot_file.php");
exec_or_die("php build.scripts/create_test_files.php");
exec_or_die("php build.scripts/inline_header_files.php src/napc.h > dist/napc.h");
exec_or_die("php build.scripts/create_static_library.php");
exec_or_die("./build.scripts/_build.sh $include_tests");
