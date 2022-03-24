#!/usr/bin/env php
<?php

$build_flags = [
	"tests" => true,
	"documentation" => true,
	"arduino-zip" => true
];
array_shift($argv);

foreach ($argv as $arg) {
	switch ($arg) {
		case "--tests":
			$build_flags["tests"] = true;
		break;

		case "--no-documentation":
			$build_flags["documentation"] = false;
		break;

		case "--no-arduino-zip":
			$build_flags["arduino-zip"] = false;
		break;

		default:
			fwrite(STDERR, "Unknown build flag '$arg'\n");
			exit(2);
	}
}


require_once __DIR__."/../x-php-utils/load.php";

define("BUILD_DATE", gmdate("d.m.Y H:i:s"));

function build($config) {
	fwrite(STDERR, "Using build flags: \n");

	foreach ($config["build_flags"] as $flag => $value) {
		fwrite(STDERR, "    $flag: ".($value ? "yes" : "no")."\n");
	}

	fwrite(STDERR, "Using build constants: \n");

	foreach ($config["build_constants"] as $key => $value) {
		fwrite(STDERR, "    $key: $value\n");
	}

	$cloneSourceTree = require __DIR__."/0.cloneSourceTree.php";

	$cloneSourceTree(function($contents, $filename) use ($config) {
		$license_header = "";

		if (
			substr($filename, -2, 2) === ".c" ||
			substr($filename, -2, 2) === ".h" ||
			substr($filename, -4, 4) === ".cpp" ||
			substr($filename, -4, 4) === ".hpp"
		) {
			// add license header file
			$license_header = "/*\n";

			foreach (file("LICENSE") as $line) {
				$license_header .= "* $line";
			}

			$license_header .= "*/\n";
		}

		foreach ($config["build_constants"] as $key => $value) {
			$contents = str_replace(
				"%BC_$key%", $value, $contents
			);
		}

		return $license_header.$contents;
	});

	$createBootFile = require __DIR__."/1.createBootFile.php";
	$createBootFile();

	if ($config["build_flags"]["tests"]) {
		$processTestFiles = require __DIR__."/2.processTestFiles.php";
		$processTestFiles();

		$createTestingFiles = require __DIR__."/3.createTestingFiles.php";
		$createTestingFiles();
	}

	$createNAPCHeaderFile = require __DIR__."/4.createNAPCHeaderFile.php";
	$createNAPCHeaderFile();

	$createStaticLibraries = require __DIR__."/5.createStaticLibraries.php";
	$createStaticLibraries();

	if ($config["build_flags"]["arduino-zip"]) {
		$packageArduinoLibrary = require __DIR__."/6.packageArduinoLibrary.php";
		$packageArduinoLibrary();
	}

	mkdir("dist.tmp", 0777, true);

	foreach (scandir("build/lib") as $output_file_name) {
		if (substr($output_file_name, 0, 1) === ".") continue;

		copy("build/lib/$output_file_name", "dist.tmp/$output_file_name");
	}

	copy("build/napc.h", "dist.tmp/napc.h");

	/**
	 * Documentation
	 */
	if ($config["build_flags"]["documentation"]) {
		$doc_extractCSymbols = require __DIR__."/10.doc_extractCSymbols.php";
		$doc_extractCSymbols();

		$doc_tagHALFunctions = require __DIR__."/11.doc_tagHALFunctions.php";
		$doc_tagHALFunctions();

		$doc_parseDocBlocks = require __DIR__."/12.doc_parseDocBlocks.php";
		$doc_parseDocBlocks();

		$doc_mapSymbolsToModules = require __DIR__."/13.doc_mapSymbolsToModules.php";
		$doc_mapSymbolsToModules();

		$doc_mapAll = require __DIR__."/14.doc_mapAll.php";
		$doc_mapAll();

		$doc_normalize = require __DIR__."/15.doc_normalize.php";
		$doc_normalize($config["build_constants"]);

		copy("build/doc/napc.json", "dist.tmp/napc.json");
	}

	/**
	 * Finish up
	 */
	XPHPUtils::shell_assertSystemCall("rm -rf dist");
	rename("dist.tmp", "dist");

	fwrite(STDERR, "All done, used build flags: \n");

	foreach ($config["build_flags"] as $flag => $value) {
		fwrite(STDERR, "    $flag: ".($value ? "yes" : "no")."\n");
	}
}

chdir(__DIR__."/../");

$arduino_friendly_version = XPHPUtils::libnapc_getReleaseVersion();
$arduino_friendly_name = "libnapc";
$arduino_friendly_url = "https://libnapc.nap.software/";

$git_branch = XPHPUtils::git_getCurrentBranch();

if ($git_branch !== "main") {
	$arduino_friendly_version = "0.0.1";
	$arduino_friendly_name = "libnapc-$git_branch";
	$arduino_friendly_url = "https://nightly.libnapc.nap.software/";
}

XPHPUtils::shell_assertSystemCall("rm -rf build dist.tmp");

build([
	"build_flags" => $build_flags,
	"build_constants" => [
		"GIT_BRANCH" => $git_branch,
		"GIT_HEAD_HASH" => XPHPUtils::git_getHEADHash(),
		"RELEASE_VERSION" => XPHPUtils::libnapc_getReleaseVersion(),
		"ARDUINO_FRIENDLY_NAME" => $arduino_friendly_name,
		"ARDUINO_FRIENDLY_VERSION" => $arduino_friendly_version,
		"ARDUINO_FRIENDLY_URL" => $arduino_friendly_url,
		"BUILD_DATE" => BUILD_DATE
	]
]);
