<?php

function libnapc_docExtract_fixClangCType($type) {
	return napphp::str_replace($type, "_Bool", "bool");
}

function libnapc_docExtract_getFunctionReturnType($qual_type) {
	// because format is:

	// RETURN_TYPE ( PARAM_1, PARAM_2, PARAM_n ... )
	$type = trim(substr($qual_type, 0, strpos($qual_type, "(")));

	return libnapc_docExtract_fixClangCType($type);
}

return [
	"description" => "Extract C-Symbols (functions, enums, structs and typedefs) from clang's raw AST.",

	"depends_on" => ["clang-ast.json"],
	"creates"    => "c-symbols.json",

	"run" => function($args) {
		$clang_ast = napphp::fs_readFileJSON(
			LIBNAPC_BUILD_FILES_DIR."/clang-ast.json"
		);

		$output_file = napphp::tmp_createFile();

		$context = [
			"clang-ast" => $clang_ast["inner"],
			"output-file" => $output_file
		];

		command_runSteps("doc-extract-c-symbols", $args, $context);

		napphp::fs_rename(
			$output_file, LIBNAPC_BUILD_FILES_DIR."/c-symbols.json"
		);
	}
];
