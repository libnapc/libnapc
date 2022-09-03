<?php

return function($args) {
	if (!napphp::fs_isDirectory(LIBNAPC_BUILD_FILES_DIR."/objects/")) {
		throw new CommandError(
			"Could not find objects files. Use 'libnapc compile' to create them."
		);
	} else if (napphp::fs_isFile(LIBNAPC_BUILD_FILES_DIR."/libnapc.a")) {
		throw new CommandError(
			"Files already linked. Use 'libnapc clean' to remove them."
		);
	}

	$object_files = napphp::fs_scandirRecursive(
		LIBNAPC_BUILD_FILES_DIR."/objects/"
	);

	$libnapc_a = napphp::tmp_createFile().".a";
	$ar_libnapc_a = escapeshellarg($libnapc_a);

	foreach ($object_files as $object_file) {
		if ($object_file["type"] !== "file") {
			throw new CommandError(
				"Detected foreign file in objects/"
			);
		} else if (!napphp::str_endsWith($object_file["basename"], ".o")) {
			throw new CommandError(
				"Detected foreign file '".$object_file["basename"]."' in objects/"
			);
		}

		$file = str_pad(
			$object_file["relative_path"], 80, " ", STR_PAD_RIGHT
		);

		fwrite(STDERR, "Linking $file ... ");

		napphp::shell_execTransparently(
			"ar rcs $ar_libnapc_a ".escapeshellarg($object_file["path"])
		);

		fwrite(STDERR, "ok\n");
	}

	napphp::fs_rename(
		$libnapc_a,
		LIBNAPC_BUILD_FILES_DIR."/libnapc.a"
	);
};
