<?php

return [
	"description" => "Finalize documentation.",

	"depends_on" => [
		"napc-mapped.json",
		"doc-blocks.json",
		"processed_files",
		"build_constants.json",
		"bundles"
	],

	"creates"    => "napc.json",

	"run" => function($args) {
		$napc = napphp::fs_readFileJSON(
			LIBNAPC_BUILD_FILES_DIR."/napc-mapped.json"
		);

		$context = [
			"downloadable_files" => [
				"libnapc-linux.tar.gz" => LIBNAPC_BUILD_FILES_DIR."/bundles/linux.tar.gz",
				"libnapc-arduino.zip"  => LIBNAPC_BUILD_FILES_DIR."/bundles/arduino.zip",
				"napc.h"               => LIBNAPC_BUILD_FILES_DIR."/processed_files/napc.h"
			],
			"output" => $napc,
			"build_constants" => napphp::fs_readFileJSON(LIBNAPC_BUILD_FILES_DIR."/build_constants.json"),
			"doc_blocks" => napphp::fs_readFileJSON(LIBNAPC_BUILD_FILES_DIR."/doc-blocks.json")
		];

		command_runSteps("doc-finalize", $args, $context);

		napphp::fs_writeFileJSONAtomic(
			LIBNAPC_BUILD_FILES_DIR."/napc.json", $context["output"], true
		);
	}
];
