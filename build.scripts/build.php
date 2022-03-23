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

fwrite(STDERR, "Will include tests: $include_tests\n");

exec_or_die("rm -rf dist");
exec_or_die("mkdir dist");
exec_or_die("mkdir dist/tmp_files");

$git = (require __DIR__."/../_git.php")();

file_put_contents(
	"dist/tmp_files/library.properties",
	str_replace(
		[
			"%LIBNAPC_VERSION_ARDUINO%",
			"%LIBNAPC_VERSION_STRING%"
		],
		[
			$git["arduino_version"],
			$git["release_version"]
		],
		file_get_contents("library.properties")
	)
);

$git_branch = $git["branch"];
$git_head = $git["HEAD"];
$release_version = $git["release_version"];

file_put_contents(
	"dist/tmp_files/arduino_git_defines.h",
	"#if !defined(LIBNAPC_GIT_BRANCH)\n".
	"#define LIBNAPC_GIT_BRANCH \"$git_branch\"\n".
	"#define LIBNAPC_GIT_HEAD \"$git_head\"\n".
	"#define LIBNAPC_RELEASE_VERSION \"$release_version\"\n".
	"#endif\n"
);

file_put_contents(
	"dist/tmp_files/napc_version.c",
	"const char *napc_version() { return \"".$git["release_version"]."\"; }".
	"const char *napc_getFullVersion() { return \"".$git["HEAD"]."\"; }"
);

exec_or_die("php build.scripts/create_boot_file.php");
exec_or_die("php build.scripts/create_test_files.php");
exec_or_die("php build.scripts/inline_header_files.php src/napc.h > dist/napc.h");
exec_or_die("php build.scripts/create_static_library.php");
exec_or_die("./build.scripts/_build.sh $include_tests");
