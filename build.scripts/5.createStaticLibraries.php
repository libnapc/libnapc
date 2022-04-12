<?php

return function() {
	$targets = [
		"x86_64-linux-gnu-gcc"  => "libnapc-linux-x86_64.a",
		"aarch64-linux-gnu-gcc" => "libnapc-linux-aarch64.a",
		"gcc"                   => "libnapc-local.a"
	];

	$c_source_files = XPHPUtils::fs_scandirRecursive("build");
	$c_source_files = array_filter($c_source_files, function($entry) {
		return $entry["type"] === "file" && substr($entry["basename"], -2, 2) === ".c";
	});

	$procs = [];

	foreach ($targets as $compiler => $output_file_name) {
		mkdir("build/object_files/$compiler/", 0777, true);

		foreach ($c_source_files as $source_file) {
			$dir = __DIR__."/../build/object_files/$compiler/".dirname(
				$source_file["rel_path"]
			);

			if (!is_dir($dir)) {
				mkdir($dir, 0777, true);
				clearstatcache();
			}

			$proc = XPHPUtils::shell_Program($compiler, [
				"-Wall", "-Wextra", "-Wpedantic", "-Werror",
				"-I".__DIR__."/../build/",
				__DIR__."/../".$source_file["abs_path"],
				"-c"
			], $dir);

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

	$index = 0;

	foreach ($targets as $compiler => $output_file_name) {
		mkdir("build/object_files/$compiler/_all");

		$object_files = XPHPUtils::fs_scandirRecursive("build/object_files/$compiler");
		$object_files = array_filter($object_files, function($entry) {
			return $entry["type"] === "file" && substr($entry["rel_path"], -2 ,2) === ".o";
		});

		foreach ($object_files as $object_file) {
			$object_file_name = str_replace("/", "_", $object_file["rel_path"]);

			copy(
				__DIR__."/../".$object_file["abs_path"],
				__DIR__."/../build/object_files/$compiler/_all/$index"."_"."$object_file_name.o"
			);

			++$index;
		}

		XPHPUtils::shell_assertSystemCall(
			"ar rcs build/lib/$output_file_name build/object_files/$compiler/_all/*.o"
		);
	}
};

