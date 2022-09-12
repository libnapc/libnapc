<?php

function libnapc_docGenAst_removeCommentsFromHeaderFile($file_path) {
	$clang_input_file = escapeshellarg($file_path);
	$output_file = napphp::tmp_createFile(".h");
	$clang_output_file = escapeshellarg($output_file);

	napphp::shell_execTransparently(
		"clang -E -P $clang_input_file -o $clang_output_file"
	);

	return $output_file;
}

return [
	"description" => "Export clang's raw AST in JSON format.",

	"depends_on" => ["processed_files"],
	"creates"    => "clang-ast.json",

	"run" => function($args) {
		$napc_h_stripped = libnapc_docGenAst_removeCommentsFromHeaderFile(
			LIBNAPC_BUILD_FILES_DIR."/processed_files/napc.h"
		);

		$ast_tmp_file = napphp::tmp_createFile(".json");
		$output_file = escapeshellarg($ast_tmp_file);

		napphp::shell_execTransparently(
			"clang -Xclang -ast-dump=json -fsyntax-only $napc_h_stripped > $output_file"
		);

		$original_ast = napphp::fs_readFileJSON($ast_tmp_file);

		napphp::fs_writeFileJSONAtomic(
			LIBNAPC_BUILD_FILES_DIR."/clang-ast.json", $original_ast, true
		);
	}
];
