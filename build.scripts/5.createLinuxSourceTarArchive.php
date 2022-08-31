<?php

return function() {
	$c_source_files = napphp::fs_scandirRecursive("build");
	$c_source_files = napphp::arr_filter($c_source_files, function($entry) {
		if ($entry["type"] !== "file") {
			return false;
		}

		return napphp::str_endsWith($entry["basename"], ".c");
	});

	$object_file_names = [];
	$cmake  = "#!/bin/bash -euf\n";

	foreach ($c_source_files as $source_file) {
		$object_file_name = md5($source_file["path"]);

		$cmake .= "printf \"compiling ".escapeshellarg($source_file["path"])." ... \"\n";
		$cmake .= "gcc -Wall -Wextra -Wpedantic -Wno-gnu-zero-variadic-macro-arguments ";
		$cmake .= "-Werror -I./build ";
		$cmake .= escapeshellarg($source_file["path"])." ";
		$cmake .= "-c -o objects/".$object_file_name.".o\n";
		$cmake .= "printf \"ok\\n\"\n";

		array_push($object_file_names, $object_file_name);
	}

	foreach ($object_file_names as $object_file_name) {
		$cmake .= "ar rcs libnapc.a ".escapeshellarg("objects/$object_file_name.o")."\n";
	}

	napphp::fs_mkdir("build/lib", 0777, true);

	$tmp_dir = napphp::tmp_createDirectory();
	napphp::fs_mkdir("$tmp_dir/objects");

	napphp::fs_writeFileStringAtomic("$tmp_dir/compile.sh", $cmake);
	napphp::fs_setFileMode("$tmp_dir/compile.sh", 0755);

	napphp::fs_copyFile(__DIR__."/linux-install-script.sh", "$tmp_dir/install.sh");
	napphp::fs_setFileMode("build.pkg/install.sh", 0755);

	napphp::fs_copy("build/", "$tmp_dir/build");

	$build_path = __DIR__."/../build/";

	napphp::proc_changeWorkingDirectory($tmp_dir, function() use ($build_path) {
		napphp::shell_execTransparently(
			"fakeroot -- tar -czvf ".escapeshellarg("$build_path/lib/libnapc-linux.tar.gz")." ."
		);

		napphp::shell_execTransparently(
			"./compile.sh"
		);

		napphp::fs_rename(
			"libnapc.a", "$build_path/lib/libnapc-local.a"
		);
	});
};


