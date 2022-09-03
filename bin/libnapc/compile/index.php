<?php

return function($args) {
	if (!napphp::fs_isDirectory(LIBNAPC_BUILD_FILES_DIR."/processed_files/")) {
		throw new CommandError(
			"Could not find preprocessed files. Use 'libnapc preprocess' to create them."
		);
	} else if (napphp::fs_isDirectory(LIBNAPC_BUILD_FILES_DIR."/objects/")) {
		throw new CommandError(
			"Files are already compiled. Use 'libnapc clean' to remove them."
		);
	}

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
	$gcc_flags = [
		"-Wall",
		"-Wextra",
		"-Wpedantic",
		"-Wno-gnu-zero-variadic-macro-arguments",
		"-Werror",
		"-I".escapeshellarg($gcc_include_path)
	];
	$gcc_flags = napphp::arr_join($gcc_flags, " ");

	$object_files_dir = napphp::tmp_createDirectory();

	foreach ($c_source_files as $c_source_file) {
		$gcc_input_file = escapeshellarg($c_source_file["path"]);

		$object_file_name = napphp::str_replace($c_source_file["relative_path"], "/", "_");
		$object_file_name = substr($object_file_name, 0, strlen($object_file_name) - 2);
		$output_file = "$object_files_dir/$object_file_name.o";

		$gcc_output_file = escapeshellarg($output_file);

		$file = str_pad(
			$c_source_file["relative_path"], 80, " ", STR_PAD_RIGHT
		);

		fwrite(
			STDOUT, "Compiling $file ... "
		);

		fflush(STDOUT);

		napphp::shell_execTransparently(
			"gcc $gcc_flags $gcc_input_file -c -o $gcc_output_file"
		);

		fwrite(STDOUT, "ok\n");
	}

	napphp::fs_rename(
		$object_files_dir,
		LIBNAPC_BUILD_FILES_DIR."/objects/"
	);
};
