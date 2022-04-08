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

define("SERVER_ROOT_URL", "http://localhost:9999");

chdir(__DIR__);

XPHPUtils::shell_assertSystemCall("rm -rf dist.tmp");
XPHPUtils::shell_assertSystemCall("rm -rf tmp/sass.cache");
XPHPUtils::shell_assertSystemCall("mkdir tmp/sass.cache");
XPHPUtils::shell_assertSystemCall("mkdir dist.tmp");

chdir("dist.tmp");

$output_type = strtolower($argv[1]);

if (!in_array($output_type, ["--optimized", "--flat"])) {
	fwrite(STDERR, "invalid output type\n");
	exit(2);
}

function download($path) {
	global $output_type;

	fwrite(STDERR, "Downloading $path\n");

	$output_dir = dirname($path);

	if (!is_dir($output_dir)) {
		mkdir($output_dir, 0777, true);
		clearstatcache();
		fwrite(STDERR, "    created $output_dir\n");
	}

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

	if (!$contents) {
		fwrite(STDERR, "Failed to download $path\n");
		exit(1);
	}

	file_put_contents($path, $contents);
}

$napc = json_decode(file_get_contents("../content/napc.json"), true);

foreach ($napc["modules"] as $module_name => $module_definitions) {
	if ($module_name === "app") continue;

	download("module/$module_name.html");

	foreach ($module_definitions as $definition) {
		$definition_name = substr($definition, 2);

		download(
			"definition/$module_name/$definition_name.html"
		);
	}
}

$documents = XPHPUtils::fs_scandirRecursive(__DIR__."/content/documents");

foreach ($documents as $document) {
	if ($document["type"] !== "file") continue;

	$filename = basename($document["rel_path"]);

	if (substr($filename, -3, 3) !== ".md") continue;

	download("document/$filename.html");
}

download("api.html");
download("releases.html");
download("home.html");
download("documentation/index.html");

download("site.css");
download("site.js");

download("index.html");

chdir(__DIR__);

XPHPUtils::shell_assertSystemCall("rm -rf dist");
XPHPUtils::shell_assertSystemCall("mv dist.tmp dist");
XPHPUtils::shell_assertSystemCall("cd dist && tar -czvf ../../dist/doc.tar.gz .");
