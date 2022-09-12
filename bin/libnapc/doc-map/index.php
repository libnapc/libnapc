<?php

return [
	"description" => "Map napc definitions to their belonging module.",

	"depends_on" => [
		"napc-definitions.json",
		"doc-blocks.json"
	],

	"creates"    => "napc-mapped.json",

	"run" => function($args) {
		$napc_definitions = napphp::fs_readFileJSON(
			LIBNAPC_BUILD_FILES_DIR."/napc-definitions.json"
		);

		$context = [
			"output" => [
				"definitions" => $napc_definitions
			]
		];

		command_runSteps("doc-map", $args, $context);

		napphp::fs_writeFileJSONAtomic(
			LIBNAPC_BUILD_FILES_DIR."/napc-mapped.json", $context["output"], true
		);
	}
];
