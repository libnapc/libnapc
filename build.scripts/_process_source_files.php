#!/usr/bin/env php
<?php
require_once __DIR__."/../php.lib/exec_or_die.php";

chdir(__DIR__."/../");

exec_or_die("rm -rf dist/processed_src");
exec_or_die("mkdir -p dist/processed_src");

$output = shell_exec("find src -name '*.c' && find src -name '*.cpp'");
$lines = explode("\n", $output);
$files = [];

$git = (require __DIR__."/../_git.php")();

foreach ($lines as $line) {
	$file = trim($line);

	if (!is_file($file)) continue;

	$dest_file_name = str_replace("/", "_", $file);

	$contents = file_get_contents($file);

	file_put_contents(
		"dist/processed_src/$dest_file_name",
		str_replace(
			[
				"%LIBNAPC_RELEASE_VERSION%",
				"%LIBNAPC_GIT_BRANCH%",
				"%LIBNAPC_GIT_HEAD%"
			],
			[
				$git["release_version"],
				$git["branch"],
				$git["HEAD"]
			],
			$contents
		)
	);
}
