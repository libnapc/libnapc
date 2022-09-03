<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];

	$context["source_entries"] = napphp::fs_scandirRecursive(
		LIBNAPC_SOURCE_FILES_DIR
	);

	fwrite(STDOUT, "Cloning source directory tree ... \n");

	$directory_tree = napphp::arr_filter($context["source_entries"], function($entry) {
		return $entry["type"] === "directory";
	});

	foreach ($directory_tree as $directory) {
		fwrite(STDOUT, "Creating '".$directory["relative_path"]."'\n");

		napphp::fs_mkdir("$output_dir/".$directory["relative_path"]);
	}
};
