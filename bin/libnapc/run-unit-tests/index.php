<?php

return [
	"description" => "Run unit tests.",

	"depends_on" => [
		"processed_files",
		"libnapc.a"
	],

	"run" => function($args) {
		$context = [
			"include_path" => LIBNAPC_BUILD_FILES_DIR."/processed_files/",
			"library_path" => LIBNAPC_BUILD_FILES_DIR."/"
		];

		command_runSteps("run-unit-tests", $args, $context);
	}
];
