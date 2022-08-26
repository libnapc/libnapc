<?php

return function() {
	$c_source_files = XPHPUtils::fs_scandirRecursive("build");
	$c_source_files = array_filter($c_source_files, function($entry) {
		return $entry["type"] === "file" && substr($entry["basename"], -2, 2) === ".c";
	});

	$object_file_names = [];
	$cmake  = "#!/bin/bash -euf\n";

	foreach ($c_source_files as $source_file) {
		$object_file_name = md5($source_file["abs_path"]);

		$cmake .= "printf \"compiling ".escapeshellarg($source_file["abs_path"])." ... \"\n";
		$cmake .= "gcc -Wall -Wextra -Wpedantic -Wno-gnu-zero-variadic-macro-arguments ";
		$cmake .= "-Werror -I./build ";
		$cmake .= escapeshellarg($source_file["abs_path"])." ";
		$cmake .= "-c -o objects/".$object_file_name.".o\n";
		$cmake .= "printf \"ok\\n\"\n";

		array_push($object_file_names, $object_file_name);
	}

	foreach ($object_file_names as $object_file_name) {
		$cmake .= "ar rcs libnapc.a ".escapeshellarg("objects/$object_file_name.o")."\n";
	}

	XPHPUtils::shell_assertSystemCall("rm -rf build.pkg && mkdir -p build.pkg/objects");

	mkdir("build/lib", 0777, true);

	file_put_contents("build.pkg/compile.sh", $cmake);
	chmod("build.pkg/compile.sh", 0755);

	copy(__DIR__."/linux-install-script.sh", "build.pkg/install.sh");
	chmod("build.pkg/install.sh", 0755);

	XPHPUtils::shell_assertSystemCall(
		"cp -r build build.pkg/build && cd build.pkg && fakeroot tar -czvf ../build/lib/libnapc-linux.tar.gz ."
	);

	XPHPUtils::shell_assertSystemCall(
		"cd build.pkg && ./compile.sh && mv libnapc.a ../build/lib/libnapc-local.a"
	);
};


