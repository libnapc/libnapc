<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];
	$generator_fn = $context["generator_fn"];

	$documents_entries = napphp::fs_scandirRecursive(
		LIBNAPC_PROJECT_ROOT_DIR."/src-documentation-interface/content/documents"
	);

	napphp::fs_mkdir("$output_dir/document");
	napphp::fs_mkdir("$output_dir/documentation");

	napphp::fs_writeFileStringAtomic(
		"$output_dir/documentation/index.html", $generator_fn("/documentation/index.html")
	);

	foreach ($documents_entries as $entry) {
		if (!napphp::str_endsWith($entry["basename"], ".md")) continue;

		$document_name = $entry["basename"];

		fwrite(STDOUT, "Exporting document '$document_name'\n");

		napphp::fs_writeFileStringAtomic(
			"$output_dir/document/$document_name.html", $generator_fn("/document/$document_name.html")
		);
	}
};
