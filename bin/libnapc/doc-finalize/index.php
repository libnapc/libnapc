<?php

function libnapc_docFinalize_searchWithGrep(
	$search_expression, $file_extension
) {
	$grep_output_file = napphp::tmp_createFile();

	napphp::shell_execute(
		"grep", [
			"cwd" => LIBNAPC_SOURCE_FILES_DIR,
			"args" => [
				"-nr",
				$search_expression,
				"--include",
				"*$file_extension", // '*.h' for example
				"."
			],
			"stdout" => $grep_output_file,
			"allow_non_zero_exit_code" => true
		]
	);

	$grep_output = napphp::fs_file($grep_output_file);
	napphp::fs_unlink($grep_output_file);

	if (sizeof($grep_output) !== 1) {
		return NULL;
	}

	$output = trim($grep_output[0]);

	$tmp = napphp::str_split($output, ":", 3);

	if (sizeof($tmp) !== 3) {
		$output_colored = napphp::terminal_colorString(
			$output, "red"
		);

		fwrite(STDERR, "Erroneous grep output '$output_colored'\n");

		return NULL;
	}

	return [
		"path" => $tmp[0],
		"line" => (int)$tmp[1]
	];
}

return [
	"description" => "Finalize documentation.",

	"depends_on" => [
		"napc-mapped.json",
		"doc-blocks.json",
		"processed_files",
		"build_constants.json",
		"bundles",
		"libnapc.a"
	],

	"creates"    => "napc.json",

	"run" => function($args) {
		$napc = napphp::fs_readFileJSON(
			LIBNAPC_BUILD_FILES_DIR."/napc-mapped.json"
		);

		$context = [
			"libnapc.a" => LIBNAPC_BUILD_FILES_DIR."/libnapc.a",
			"downloadable_files" => [
				"libnapc-linux.tar.gz" => LIBNAPC_BUILD_FILES_DIR."/bundles/linux.tar.gz",
				"libnapc-arduino.zip"  => LIBNAPC_BUILD_FILES_DIR."/bundles/arduino.zip",
				"napc.h"               => LIBNAPC_BUILD_FILES_DIR."/processed_files/libnapc.h"
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
