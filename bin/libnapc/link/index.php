<?php

return [
	"description" => "Create archive file (.a) of generated object files.",

	"depends_on" => ["objects"],
	"creates"    => "libnapc.a",

	"run" => function($args) {
		$object_files = napphp::fs_scandirRecursive(
			LIBNAPC_BUILD_FILES_DIR."/objects/"
		);

		$libnapc_a = napphp::tmp_createFile().".a";

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

			fwrite(STDOUT, "Linking $file ... ");
			fflush(STDOUT);

			napphp::shell_execute(
				"ar", [
					"args" => [
						"rcs",
						$libnapc_a,
						$object_file["path"]
					]
				]
			);

			fwrite(STDOUT, "ok\n");
		}

		napphp::fs_rename(
			$libnapc_a,
			LIBNAPC_BUILD_FILES_DIR."/libnapc.a"
		);
	}
];
