#!/usr/bin/env php
<?php

class CommandError extends Exception {}

// todo: check php version
$NAPPHP_LOAD_PATH = getenv("NAPPHP_LOAD_PATH");

if (!is_file($NAPPHP_LOAD_PATH)) {
	fwrite(STDERR, "Either NAPPHP_LOAD_PATH is not set, or does not exist.\n");
	exit(2);
}

require_once $NAPPHP_LOAD_PATH;

fwrite(STDERR, "[debug] Using napphp version v".napphp::info_getVersion()."\n");

napphp::set("tmp_dir", __DIR__."/../tmp.d/");

array_shift($argv); // clear $argv[0] because its always the programs name

if (!sizeof($argv)) {
	fwrite(STDERR, "Usage: libnapc [command]\n");
	exit(2);
}

define("LIBNAPC_PROJECT_ROOT_DIR", __DIR__."/../");
define("LIBNAPC_SOURCE_FILES_DIR", __DIR__."/../src/");
define("LIBNAPC_TEST_SOURCE_FILES_DIR", __DIR__."/../__tests__/");
define("LIBNAPC_BUILD_FILES_DIR", __DIR__."/../build_files/");

function loadCommand($command_name) {
	// use cache to prevent loading the same command file twice
	static $cache = [];

	if (napphp::arr_keyExists($cache, $command_name)) {
		return $cache[$command_name];
	}

	$cache[$command_name] = require __DIR__."/libnapc/$command_name/index.php";

	return $cache[$command_name];
}

function command_runSteps($name, $args, $initial_context = []) {
	$steps = napphp::fs_scandirRecursive(__DIR__."/libnapc/$name/steps/");
	$steps = napphp::arr_filter($steps, function($entry) {
		if ($entry["type"] === "directory") return false;
		if (!napphp::str_endsWith($entry["basename"], ".php")) return false;

		return !napphp::str_startsWith($entry["basename"], "_");
	});
	$steps = napphp::arr_map($steps, function($entry) {
		return $entry["basename"];
	});

	usort($steps, function($a, $b) {
		$a_no = (int)(napphp::str_split($a, ".", 2)[0]);
		$b_no = (int)(napphp::str_split($b, ".", 2)[0]);

		if ($a_no > $b_no) return 1;

		return -1;
	});

	$context = $initial_context;

	foreach ($steps as $step) {
		$step_fn = require __DIR__."/libnapc/$name/steps/$step";

		$step_fn($args, $context);
	}
}

$command_name = array_shift($argv);
$command = loadCommand($command_name);

function parseArguments($args) {
	$ret = [
		"flags" => []
	];

	while (sizeof($args)) {
		$arg = array_shift($args);

		if (napphp::str_startsWith($arg, "--")) {
			$ret["flags"][substr($arg, 2)] = true;
		}
	}

	return $ret;
}

function getCommandNameByOutputPath($output_path) {
	$commands = napphp::fs_scandir(__DIR__."/libnapc/");

	foreach ($commands as $command_name) {
		$command = loadCommand($command_name);

		if (!napphp::arr_keyExists($command, "creates")) continue;

		if ($command["creates"] === $output_path) {
			return $command_name;
		}
	}

	return "?";
}

try {
	# check dependencies
	if (napphp::arr_keyExists($command, "depends_on")) {
		foreach ($command["depends_on"] as $path) {
			if (!napphp::fs_exists(LIBNAPC_BUILD_FILES_DIR."/$path")) {
				$cmd = getCommandNameByOutputPath($path);

				fwrite(STDERR, "$path is missing\n");
				fwrite(STDERR, "Generate it by running 'libnapc $cmd'\n");
				exit(2);
			}
		}
	}

	# check if already created
	if (napphp::arr_keyExists($command, "creates")) {
		$path = $command["creates"];

		if (napphp::fs_exists(LIBNAPC_BUILD_FILES_DIR."/$path")) {
			fwrite(STDERR, "Output of command already created. Run 'libnapc clean' to start over.\n");
			exit(2);
		}
	}

	$command_fn = $command["run"];
	$command_fn(parseArguments($argv));
} catch (CommandError $e) {
	fwrite(STDERR, "Command failed: ".$e->getMessage()."\n");
	exit(1);
} catch (Exception $e) {
	fwrite(STDERR, "$e\n");
	exit(1);
}
