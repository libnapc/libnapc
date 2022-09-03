<?php

return function($args, &$context) {
	if (napphp::arr_keyExists($args["flags"], "no-tests")) {
		return;
	}

	$output_dir = $context["output_dir"];

	$context["test_source_entries"] = napphp::fs_scandirRecursive(
		LIBNAPC_TEST_SOURCE_FILES_DIR
	);

	fwrite(STDERR, "Cloning tests source directory tree ... \n");

	$directory_tree = napphp::arr_filter($context["test_source_entries"], function($entry) {
		return $entry["type"] === "directory";
	});

	foreach ($directory_tree as $directory) {
		fwrite(STDERR, "Creating '__tests__/".$directory["relative_path"]."'\n");

		napphp::fs_mkdir("$output_dir/__tests__/".$directory["relative_path"]);
	}
};
