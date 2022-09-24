<?php

return [
	"description" => "Export documentation.",

	"depends_on" => [
		"napc.json"
	],

	"creates" => ["documentation_files", "documentation.tar.gz"],

	"run" => function($args) {
		$sass_cache_dir = napphp::tmp_createDirectory();
		$output_tar = napphp::tmp_createFile(".tar.gz");
		$output_dir = napphp::tmp_createDirectory();

		$page_generator = require LIBNAPC_PROJECT_ROOT_DIR."/src-documentation-interface/page_generator.php";

		$napc = napphp::fs_readFileJSON(LIBNAPC_BUILD_FILES_DIR."/napc.json");

		$generator_fn = function($request_path) use (&$page_generator, $sass_cache_dir) {
			$response = $page_generator(
				$request_path, [
					"x-sass-cache-dir" => $sass_cache_dir
				]
			);

			return $response["body"];
		};

		$context = [
			"napc" => $napc,
			"generator_fn" => $generator_fn,
			"output_tar" => $output_tar,
			"output_dir" => $output_dir
		];

		command_runSteps("doc-export", $args, $context);

		napphp::fs_rename(
			$output_tar,
			LIBNAPC_BUILD_FILES_DIR."/documentation.tar.gz"
		);

		napphp::fs_rename(
			$output_dir,
			LIBNAPC_BUILD_FILES_DIR."/documentation_files"
		);
	}
];
