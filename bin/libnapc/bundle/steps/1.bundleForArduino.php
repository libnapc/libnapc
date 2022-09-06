<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];

	napphp::fs_mkdir("$output_dir/arduino/src");

	foreach ($context["preprocessed_files_tree"] as $entry) {
		napphp::fs_mkdir("$output_dir/arduino/src/".$entry["relative_path"]);
	}

	$arduino_source_files = napphp::arr_filter(
		$context["preprocessed_files"], function($entry) {
			return true;
		}
	);

	foreach ($arduino_source_files as $arduino_source_file) {
		napphp::fs_copyFile(
			$arduino_source_file["path"], "$output_dir/arduino/src/".$arduino_source_file["relative_path"]
		);
	}

	napphp::fs_rename(
		"$output_dir/arduino/src/library.properties", "$output_dir/arduino/library.properties"
	);

	napphp::fs_copy(
		LIBNAPC_PROJECT_ROOT_DIR."/arduino_examples",
		"$output_dir/arduino/examples"
	);

	napphp::fs_copy(LIBNAPC_PROJECT_ROOT_DIR."/README.md", "$output_dir/arduino/README.md");
	napphp::fs_copy(LIBNAPC_PROJECT_ROOT_DIR."/LICENSE", "$output_dir/arduino/LICENSE");

	napphp::proc_changeWorkingDirectory(
		"$output_dir/arduino", function() {

			napphp::shell_execTransparently(
				"zip -r ../arduino.zip ."
			);
		}
	);

	napphp::fs_delete("$output_dir/arduino");
};
