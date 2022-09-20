<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];

	napphp::fs_mkdir("$output_dir/linux/src");
	napphp::fs_mkdir("$output_dir/linux/objects");

	foreach ($context["preprocessed_files_tree"] as $entry) {
		napphp::fs_mkdir("$output_dir/linux/src/".$entry["relative_path"]);
	}

	$linux_source_files = napphp::arr_filter(
		$context["preprocessed_files"], function($entry) {
			if (napphp::str_endsWith($entry["basename"], ".h")) return true;
			if (napphp::str_endsWith($entry["basename"], ".c")) return true;

			return false;
		}
	);

	$compile_script = "#!/bin/bash -euf\n";

	$compiler_flags = napphp::fs_file(LIBNAPC_PROJECT_ROOT_DIR."/compile_flags.txt");
	$gcc_flags = napphp::arr_map($compiler_flags, function($line) {
		return trim($line);
	});

	$gcc_flags = napphp::arr_join($gcc_flags, " ");

	$object_files = [];

	foreach ($linux_source_files as $linux_source_file) {
		fwrite(STDOUT, "Copying '".$linux_source_file["relative_path"]."'\n");

		if (napphp::str_endsWith($linux_source_file["basename"], ".c")) {
			$gcc_input_file = escapeshellarg("src/".$linux_source_file["relative_path"]);
			$object_file_name = md5($linux_source_file["relative_path"]);
			$gcc_output_file = escapeshellarg("objects/$object_file_name.o");

			$compile_script .= "printf \"Compiling $gcc_input_file\\n\"\n";
			$compile_script .= "gcc $gcc_flags $gcc_input_file -c -o $gcc_output_file\n";

			array_push($object_files, $object_file_name);
		}

		napphp::fs_copyFile(
			$linux_source_file["path"], "$output_dir/linux/src/".$linux_source_file["relative_path"]
		);
	}

	foreach ($object_files as $object_file_name) {
		$compile_script .= "printf \"Linking objects/$object_file_name.o\\n\"\n";
		$compile_script .= "ar rcs libnapc.a objects/$object_file_name.o\n";
	}

	napphp::fs_writeFileStringAtomic("$output_dir/linux/compile.sh", $compile_script);
	napphp::fs_setFileMode("$output_dir/linux/compile.sh", 0755);

	napphp::fs_copyFile(__DIR__."/linux-files/install.sh", "$output_dir/linux/install.sh");
	napphp::fs_createSymbolicLink("$output_dir/linux/napc.h", "src/napc.h");

	napphp::shell_execute(
		"fakeroot", [
			"cwd"  => "$output_dir/linux",
			"args" => [
				"tar", "-czvf", "../linux.tar.gz", "."
			]
		]
	);

	napphp::fs_delete("$output_dir/linux");
};
