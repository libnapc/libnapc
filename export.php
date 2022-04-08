#!/usr/bin/env php
<?php
require_once __DIR__."/../x-php-utils/load.php";

if (sizeof($argv) !== 2) {
	fwrite(STDERR, "Output type is missing\n");
	exit(1);
}

/**
 * This script creates the documentation.
 */

define("SERVER_ROOT_URL", "http://localhost:9999/");

chdir(__DIR__);

XPHPUtils::shell_assertSystemCall("rm -rf dist.tmp");
// todo: do not delete .gitkeep file
XPHPUtils::shell_assertSystemCall("rm -rf sass.cache");
XPHPUtils::shell_assertSystemCall("mkdir sass.cache");
XPHPUtils::shell_assertSystemCall("mkdir dist.tmp");

$output_type = strtolower($argv[1]);

if (!in_array($output_type, ["--optimized", "--flat"])) {
	fwrite(STDERR, "invalid output type\n");
	exit(2);
}

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

download("downloads.html");

XPHPUtils::shell_assertSystemCall("rm -rf dist");
XPHPUtils::shell_assertSystemCall("mv dist.tmp dist");
XPHPUtils::shell_assertSystemCall("cd dist && tar -czvf ../../dist/doc.tar.gz .");
