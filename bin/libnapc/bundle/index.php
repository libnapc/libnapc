<?php

return [
	"description" => "Bundle preprocessed source files for distribution (arduino, linux).",

	"depends_on" => ["processed_files"],
	"creates"    => "bundles",

	"run" => function($args) {
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

		$context = [
			"output_dir" => $temp_dir,
			"preprocessed_files" => $preprocessed_files,
			"preprocessed_files_tree" => $preprocessed_files_tree,
			"release_version" => libnapc_getReleaseVersion()
		];

		command_runSteps("bundle", $args, $context);

		napphp::fs_rename(
			$temp_dir, LIBNAPC_BUILD_FILES_DIR."/bundles/"
		);
	}
];
