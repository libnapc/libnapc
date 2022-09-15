<?php

function libnapc_docExtract_parseSingleArrayCTypeInfo($element) {
	$tmp = substr($element, 1);

	return (int)substr($tmp, 0, strlen($tmp) - 1);
}

function libnapc_docExtract_parseArrayCTypeInfo($type) {
	if (!napphp::str_contains($type, "[")) {
		return false;
	}

	// format is: TYPE*SPACE*[]
	list($type_name, $array_info) = napphp::str_split($type, " ", 2);

	$tmp = napphp::str_split($array_info, "][");

	// if $tmp is one element format is: [X]
	if (sizeof($tmp) === 1) {
		return [
			"type_name" => $type_name,
			"dimension" => [
				libnapc_docExtract_parseSingleArrayCTypeInfo($tmp[0])
			]
		];
	}

	// first and last elements are special cases

	// first element is [N
	// last element is N]
	$first = libnapc_docExtract_parseSingleArrayCTypeInfo(array_shift($tmp)."]");
	$last = libnapc_docExtract_parseSingleArrayCTypeInfo("[".array_pop($tmp));

	$tmp = napphp::arr_map($tmp, function($element) {
		return (int)$element;
	});

	return [
		"type_name" => $type_name,
		"dimension" => [
			$first,
			...$tmp,
			$last
		]
	];
}

function libnapc_docExtract_fixClangCType($type) {
	$type = napphp::str_replace($type, "_Bool", "bool");

	// parse ARRAY_TYPE [NUM_ELEMENTS][..][..]
	$array_info = libnapc_docExtract_parseArrayCTypeInfo($type);

	if ($array_info === false) {
		return $type;
	}

	if (sizeof($array_info["dimension"]) > 1) {
		throw new Exception("Multidimensional array detected. Not supported yet.");
	}

	return [
		$array_info["type_name"],
		$array_info["dimension"][0]
	];
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
