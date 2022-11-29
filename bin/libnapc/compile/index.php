<?php

return [
	"description" => "Create object files of preprocessed source file.",

	"depends_on" => ["processed_files"],
	"creates"    => "objects",

	"run" => function($args) {
		$ok_colored = napphp::terminal_colorString("ok", "green");

		$preprocessed_entries = napphp::fs_scandirRecursive(
			LIBNAPC_BUILD_FILES_DIR."/processed_files/"
		);

		$c_source_files = napphp::arr_filter($preprocessed_entries, function($entry) {
			if ($entry["type"] !== "file") {
				return false;
			}

			return napphp::str_endsWith($entry["basename"], ".c");
		});

		$gcc_include_path = LIBNAPC_BUILD_FILES_DIR."/processed_files/";

		$compiler_flags = napphp::fs_file(LIBNAPC_PROJECT_ROOT_DIR."/compile_flags.txt");
		$gcc_flags = napphp::arr_map($compiler_flags, function($line) {
			return trim($line);
		});
		// remove -I./src
		$gcc_flags = napphp::arr_filter($gcc_flags, function($flag) {
			return !napphp::str_startsWith($flag, "-I");
		});

		// add -DLIBNAPC_INCLUDE_TESTS if invoked with '--with-tests':
		$with_tests_enabled = $args["flags"]["with-tests"] ?? false;

		if ($with_tests_enabled) {
			array_push($gcc_flags, "-DLIBNAPC_INCLUDE_TESTS=1");
		}

		// add -DLIBNAPC_DEBUG if invoked with '--with-debug':
		$with_debug_enabled = $args["flags"]["with-debug"] ?? false;

		// always set debug if '--with-tests' was specified
		if ($with_tests_enabled) {
			$with_debug_enabled = true;
		}

		if ($with_debug_enabled) {
			array_push($gcc_flags, "-DLIBNAPC_DEBUG=1");
		}

		// add -I./build_files/processed_files/
		array_push($gcc_flags, "-I$gcc_include_path");

		$object_files_dir = napphp::tmp_createDirectory();

		foreach ($c_source_files as $c_source_file) {
			$object_file_name = napphp::str_replace($c_source_file["relative_path"], "/", "_");
			$object_file_name = substr($object_file_name, 0, strlen($object_file_name) - 2);
			$output_file = "$object_files_dir/$object_file_name.o";

			$padded_line = str_pad(
				"Compiling '".$c_source_file["relative_path"]."'", 80, " ", STR_PAD_RIGHT
			);

			fwrite(STDOUT, $padded_line." ... ");

			fflush(STDOUT);

			napphp::shell_execute(
				"gcc", [
					"args" => [
						...$gcc_flags,
						// input file
						$c_source_file["path"],
						// create object file
						"-c",
						// store object file at path
						"-o",
						$output_file
					]
				]
			);

			fwrite(STDOUT, "$ok_colored\n");
		}

		napphp::fs_rename(
			$object_files_dir,
			LIBNAPC_BUILD_FILES_DIR."/objects/"
		);
	}
];
