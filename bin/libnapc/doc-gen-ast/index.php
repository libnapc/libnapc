<?php

function libnapc_docGenAst_removeCommentsFromHeaderFile($file_path) {
	$output_file = napphp::tmp_createFile(".h");

	napphp::shell_execute(
		"clang", [
			"args" => [
				"-E",
				"-P",
				$file_path,
				"-o",
				$output_file
			]
		]
	);

	return $output_file;
}

return [
	"description" => "Export clang's raw AST in JSON format.",

	"depends_on" => ["processed_files"],
	"creates"    => "clang-ast.json",

	"run" => function($args) {
		$napc_h_stripped = libnapc_docGenAst_removeCommentsFromHeaderFile(
			LIBNAPC_BUILD_FILES_DIR."/processed_files/libnapc.h"
		);

		$ast_tmp_file = napphp::tmp_createFile(".json");

		napphp::shell_execute(
			"clang", [
				"args" => [
					"-Xclang",
					"-ast-dump=json",
					"-fsyntax-only",
					$napc_h_stripped
				],
				"stdout" => $ast_tmp_file
			]
		);

		$original_ast = napphp::fs_readFileJSON($ast_tmp_file);

		napphp::fs_writeFileJSONAtomic(
			LIBNAPC_BUILD_FILES_DIR."/clang-ast.json", $original_ast, true
		);
	}
];
