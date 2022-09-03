<?php

function libnapc_preprocess_processFile(
	$filename,
	$file_contents,
	$build_constants
) {
	$license_header = "";
	$add_license = false;

	if (napphp::str_endsWith($filename, ".c")) $add_license = true;
	if (napphp::str_endsWith($filename, ".h")) $add_license = true;
	if (napphp::str_endsWith($filename, ".cpp")) $add_license = true;
	if (napphp::str_endsWith($filename, ".hpp")) $add_license = true;

	if ($add_license) {
		$license_header = "/*\n";

		foreach (napphp::fs_file(LIBNAPC_PROJECT_ROOT_DIR."/LICENSE") as $line) {
			$license_header .= "* $line";
		}

		$license_header .= "*/\n";
	}

	foreach ($build_constants as $key => $value) {
		$file_contents = napphp::str_replace(
			$file_contents, "%BC_$key%", $value
		);
	}

	return $license_header.$file_contents;
}

return function($args, &$context) {
	$output_dir = $context["output_dir"];

	$source_files = napphp::arr_filter($context["source_entries"], function($entry) {
		return $entry["type"] === "file";
	});

	foreach ($source_files as $source_file) {
		fwrite(STDOUT, "Preprocessing '".$source_file["relative_path"]."'\n");

		$source_file_content = napphp::fs_readFileString($source_file["path"]);
		$source_file_content = libnapc_preprocess_processFile(
			$source_file["basename"],
			$source_file_content,
			$context["build_constants"]
		);

		napphp::fs_writeFileStringAtomic(
			"$output_dir/".$source_file["relative_path"], $source_file_content
		);
	}
};
