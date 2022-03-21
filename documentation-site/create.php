<?php
require_once __DIR__."/../php.lib/exec_or_die.php";

if (sizeof($argv) !== 3) {
	fwrite(STDERR, "Version and output type missing\n");
	exit(1);
}

/**
 * This script creates the documentation.
 */

define("SERVER_ROOT_URL", "http://localhost:9999/");
define("VERSION_FILE_PATH", __DIR__."/doc/dynamic/version.php");

chdir(__DIR__);

exec_or_die("rm -rf dist.tmp");
exec_or_die("rm -rf sass.cache");
exec_or_die("mkdir sass.cache");
exec_or_die("mkdir dist.tmp");
exec_or_die("rm -rf doc/dynamic");
exec_or_die("mkdir doc/dynamic");

$version = $argv[1];
$output_type = strtolower($argv[2]);

if (!in_array($output_type, ["--optimized", "--flat"])) {
	fwrite(STDERR, "invalid output type\n");
	exit(2);
}

if ($version === "git") {
	$version = trim(exec("git rev-parse HEAD"));
}

file_put_contents(VERSION_FILE_PATH, $version);

clearstatcache();

function download($path) {
	global $output_type;

	fwrite(STDERR, "Creating $path\n");

	$opts = [];

	if ($output_type === "--optimized") {
		$opts = [
			"http" => [
				"header" => "x-optimized-output: yes\r\n"
			]
		];
	}

	$context = stream_context_create($opts);

	$contents = file_get_contents(SERVER_ROOT_URL."/$path", false, $context);

	file_put_contents("dist.tmp/$path", $contents);
}

$napc = json_decode(file_get_contents(__DIR__."/doc/napc.json"), true);

foreach ($napc["modules"] as $module_name => $module_definitions) {
	mkdir("dist.tmp/$module_name");

	foreach ($module_definitions as $module_definition) {
		download("$module_name/".substr($module_definition, 2).".html");
	}

	download("$module_name.html");
}

download("index.html");
download("install.html");

if ($output_type === "--optimized") {
	download("style.css");
	download("script.js");
}

exec_or_die("rm -rf dist");
exec_or_die("rm -rf doc/dynamic");
exec_or_die("mv dist.tmp dist");
exec_or_die("cd dist && tar -czvf ../../dist/doc.tar.gz .");
