#!/usr/bin/env php
<?php

require_once __DIR__."/../x-php-utils/load.php";

define("BUILD_DATE", gmdate("d.m.Y H:i:s"));

function build($config) {
	$cloneSourceTree = require __DIR__."/0.cloneSourceTree.php";

	$cloneSourceTree(function($contents) use ($config) {
		foreach ($config["build_constants"] as $key => $value) {
			$contents = str_replace(
				"%BC_$key%", $value, $contents
			);
		}

		return $contents;
	});

	$createBootFile = require __DIR__."/1.createBootFile.php";
	$createBootFile();

	if ($config["include_tests"]) {
		$processTestFiles = require __DIR__."/2.processTestFiles.php";
		$processTestFiles();

		$createTestingFiles = require __DIR__."/3.createTestingFiles.php";
		$createTestingFiles();
	}

	$createNAPCHeaderFile = require __DIR__."/4.createNAPCHeaderFile.php";
	$createNAPCHeaderFile();

	$createStaticLibraries = require __DIR__."/5.createStaticLibraries.php";
	$createStaticLibraries();

	$packageArduinoLibrary = require __DIR__."/6.packageArduinoLibrary.php";
	$packageArduinoLibrary();

	mkdir("dist.tmp", 0777, true);

	foreach (scandir("build/lib") as $output_file_name) {
		if (substr($output_file_name, 0, 1) === ".") continue;

		copy("build/lib/$output_file_name", "dist.tmp/$output_file_name");
	}

	copy("build/napc.h", "dist.tmp/napc.h");

	XPHPUtils::shell_assertSystemCall("rm -rf dist");
	rename("dist.tmp", "dist");
}

chdir(__DIR__."/../");

$arduino_friendly_version = XPHPUtils::libnapc_getReleaseVersion();

if (XPHPUtils::git_getCurrentBranch() !== "main") {
	$arduino_friendly_version = "0.0.1";
}

XPHPUtils::shell_assertSystemCall("rm -rf build");

build([
	"build_constants" => [
		"GIT_BRANCH" => XPHPUtils::git_getCurrentBranch(),
		"GIT_HEAD_HASH" => XPHPUtils::git_getHEADHash(),
		"RELEASE_VERSION" => XPHPUtils::libnapc_getReleaseVersion(),
		"ARDUINO_FRIENDLY_VERSION" => $arduino_friendly_version,
		"BUILD_DATE" => BUILD_DATE
	],
	"include_tests" => !(isset($argv[1]) && $argv[1] == "--no-tests")
]);
