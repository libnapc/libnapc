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

	libnapc_run_steps("bundle", $args, [
		"output_dir" => $temp_dir,
		"preprocessed_entries" => $preprocessed_entries
	]);

	napphp::fs_rename(
		$temp_dir, LIBNAPC_BUILD_FILES_DIR."/bundles/"
	);
};
