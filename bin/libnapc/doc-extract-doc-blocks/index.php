<?php

return [
	"description" => "Extract doc-block comments from preprocessed source code.",

	"depends_on" => ["processed_files"],
	"creates"    => "doc-blocks.json",

	"run" => function($args) {
		$context = [
			"header" => napphp::fs_readFileString(
				LIBNAPC_BUILD_FILES_DIR."/processed_files/napc.h"
			),
			"doc_block_comments" => []
		];

		command_runSteps("doc-extract-doc-blocks", $args, $context);

		napphp::fs_writeFileJSONAtomic(
			LIBNAPC_BUILD_FILES_DIR."/doc-blocks.json", $context["doc_blocks"], true
		);
	}
];
