#!/usr/bin/env php
<?php

require_once __DIR__."/../load-napphp.php";

class CommandError extends Exception {}

array_shift($argv); // clear $argv[0] because its always the programs name

function loadCommand($command_name) {
	// use cache to prevent loading the same command file twice
	static $cache = [];

	if (napphp::arr_keyExists($cache, $command_name)) {
		return $cache[$command_name];
	}

	$cache[$command_name] = require __DIR__."/libnapc/$command_name/index.php";

	return $cache[$command_name];
}

function getAvailableCommands() {
	$ret = [];
	$commands = napphp::fs_scandir(__DIR__."/libnapc/");

	foreach ($commands as $command_name) {
		$command = loadCommand($command_name);

		if (napphp::arr_keyExists($command, "description")) {
			$ret[$command_name] = $command["description"];
		} else {
			$ret[$command_name] = "No description available.";
		}
	}

	return $ret;
}

function libnapc_getReleaseVersion() {
	$libnapc_release_version = getenv("LIBNAPC_RELEASE_VERSION");

	if (napphp::str_startsWith($libnapc_release_version, "v")) {
		return substr(
			$libnapc_release_version, 1
		);
	}

	$git_branch = napphp::git_getCurrentBranch();
	$git_HEAD = napphp::git_getHEADSha1Hash();

	return $git_branch."-".substr($git_HEAD, 0, 7);
}

if (!sizeof($argv)) {
	fwrite(STDERR, "Usage: libnapc [command]\n");

	foreach (getAvailableCommands() as $command_name => $description) {
		if (is_array($description)) {
			$description = napphp::arr_join($description, "\n    ");
		}

		fprintf(
			STDERR,
			"\n  %-10s\n    %s\n\n",
			napphp::terminal_colorString($command_name, "yellow"),
			$description
		);
	}

	exit(2);
}

define("LIBNAPC_PROJECT_ROOT_DIR", __DIR__."/../");
define("LIBNAPC_SOURCE_FILES_DIR", __DIR__."/../src/");
define("LIBNAPC_TEST_SOURCE_FILES_DIR", __DIR__."/../__tests__/");
define("LIBNAPC_BUILD_FILES_DIR", __DIR__."/../build_files/");

function command_runSteps($name, $args, &$initial_context = []) {
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

	$context = &$initial_context;

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

		$command_creates = napphp::util_arrayify($command["creates"]);

		if (in_array($output_path, $command_creates)) {
			return $command_name;
		}
	}

	return "?";
}

try {
	# check dependencies
	if (napphp::arr_keyExists($command, "depends_on")) {
		$missing_dependency = false;

		foreach ($command["depends_on"] as $path) {
			if (!napphp::fs_exists(LIBNAPC_BUILD_FILES_DIR."/$path")) {
				$missing_dependency = true;

				$cmd = getCommandNameByOutputPath($path);
				$colored_cmd = napphp::terminal_colorString($cmd, "cyan");
				$colored_path = napphp::terminal_colorString("build_files/$path", "yellow");

				fwrite(STDERR, "'$colored_path' is missing\n");
				fwrite(STDERR, ">>> Generate it by running 'libnapc $colored_cmd'\n");
			}
		}

		if ($missing_dependency) {
			exit(2);
		}
	}

	# check if already created
	if (napphp::arr_keyExists($command, "creates")) {
		$paths = napphp::util_arrayify($command["creates"]);

		foreach ($paths as $path) {
			if (napphp::fs_exists(LIBNAPC_BUILD_FILES_DIR."/$path")) {
				fwrite(STDERR, "Output of command already created. Run 'libnapc clean' to start over.\n");
				exit(2);
			}
		}
	}

	$command_fn = $command["run"];

	$colored_current_cmd = napphp::terminal_colorString("libnapc $command_name", "yellow");

	fwrite(STDERR, "Running '$colored_current_cmd'\n");

	$command_fn(parseArguments($argv));
} catch (CommandError $e) {
	fwrite(STDERR, "Command failed: ".$e->getMessage()."\n");
	exit(1);
} catch (Exception $e) {
	fwrite(STDERR, "$e\n");
	exit(1);
}
