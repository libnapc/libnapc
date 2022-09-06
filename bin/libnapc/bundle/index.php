<?php

return function($args) {
	if (!napphp::fs_isDirectory(LIBNAPC_BUILD_FILES_DIR."/processed_files/")) {
		throw new CommandError(
			"Could not find preprocessed files. Use 'libnapc preprocess' to create them."
		);
	} else if (napphp::fs_isDirectory(LIBNAPC_BUILD_FILES_DIR."/bundles/")) {
		throw new CommandError(
			"Files are already bundled. Use 'libnapc clean' to remove them."
		);
	}

	$temp_dir = napphp::tmp_createDirectory();

	$preprocessed_entries = napphp::fs_scandirRecursive(
		LIBNAPC_BUILD_FILES_DIR."/processed_files/"
	);

	$preprocessed_files = napphp::arr_filter($preprocessed_entries, function($entry) {
		return $entry["type"] === "file";
	});

	$preprocessed_files_tree = napphp::arr_filter($preprocessed_entries, function($entry) {
		return $entry["type"] === "directory";
	});

	libnapc_run_steps("bundle", $args, [
		"output_dir" => $temp_dir,
		"preprocessed_files" => $preprocessed_files,
		"preprocessed_files_tree" => $preprocessed_files_tree
	]);

	napphp::fs_rename(
		$temp_dir, LIBNAPC_BUILD_FILES_DIR."/bundles/"
	);
};
