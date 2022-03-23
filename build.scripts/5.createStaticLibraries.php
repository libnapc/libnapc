<?php

return function() {
	$targets = [
		"x86_64-linux-gnu-gcc" => "libnapc-x86_64.a",
		"aarch64-linux-gnu-gcc" => "libnapc-aarch64.a"
	];

	$c_source_files = XPHPUtils::fs_scandirRecursive("build");
	$c_source_files = array_filter($c_source_files, function($entry) {
		return $entry["type"] === "file" && substr($entry["basename"], -2, 2) === ".c";
	});

	$procs = [];

	foreach ($targets as $compiler => $output_file_name) {
		mkdir("build/object_files/$compiler/", 0777, true);

		foreach ($c_source_files as $source_file) {
			$object_file = "build/object_files/$compiler/".str_replace("/", "_", $source_file["rel_path"]).".o";

			$proc = XPHPUtils::shell_Programm($compiler, [
				"-Wall", "-Wextra", "-Wpedantic", "-Werror", "-I./src/",
				$source_file["abs_path"], "-c", "-o", $object_file
			]);

			$procs[] = $proc;
		}
	}

	fwrite(STDERR, "Waiting for compilation to be done ... \n");

	while (true) {
		$n_procs_done = 0;

		foreach ($procs as $proc) {
			if ($proc->getExitCode() !== -1) {
				$exit_code = $proc->getExitCode();

				fwrite(STDERR, $proc->getCommand()."\n");

				if ($exit_code !== 0) {
					fwrite(STDERR, "\033[0;31m");
				} else {
					fwrite(STDERR, "\033[1;30m");
				}

				foreach ($proc->getOutput() as $stream => $output) {
					$lines = explode("\n", $output);

					foreach ($lines as $line) {
						fwrite(STDERR, "$stream: $line\n");
					}
				}

				fwrite(STDERR, "\033[0;0m");

				if ($exit_code !== 0) {
					exit(1);
				}

				$n_procs_done++;
			}
		}

		if ($n_procs_done === sizeof($procs)) break;
	}

	mkdir("build/lib", 0777, true);

	foreach ($targets as $compiler => $output_file_name) {
		XPHPUtils::shell_assertSystemCall(
			"ar rcs build/lib/$output_file_name build/object_files/$compiler/*.o"
		);
	}
};

