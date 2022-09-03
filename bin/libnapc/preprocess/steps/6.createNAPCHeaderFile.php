<?php

function libnapc_preprocess_inlineHeaderIncludes(
	$file, $context,
	&$included_headers = [], $indent_level = 0
) {
	$lines = napphp::fs_file($file);
	$ret = "";

	$indentation = str_repeat("    ", $indent_level);

	foreach ($lines as $line) {
		$trimmed_line = trim($line);

		if (napphp::str_startsWith($trimmed_line, "#include")) {
			$include_expr = trim(substr($trimmed_line, strlen("#include")));
			$include_path = substr($include_expr, 1);
			$include_path = substr($include_path, 0, strpos($include_path, ">"));

			$absolute_include_path = $context.$include_path;

			$ret .= "\n/* original: $trimmed_line */\n";

			if (napphp::fs_isAFile($absolute_include_path)) {
				$real_include_path = napphp::fs_realpath($absolute_include_path);

				if (!napphp::arr_keyExists($included_headers, $real_include_path)) {
					$ret .= libnapc_preprocess_inlineHeaderIncludes(
						$absolute_include_path, $context,
						$included_headers,
						$indent_level + 1
					);
				} else {
					$ret .= "/* header file already included */\n";
				}

				$included_headers[$real_include_path] = 1;
			} else {
				$ret .= $indentation.trim($line)."\n";
			}
		} else {
			$ret .= $indentation.$line;
		}
	}

	return $ret;
}

return function($args, &$context) {
	$output_dir = $context["output_dir"];

	$file_contents = libnapc_preprocess_inlineHeaderIncludes(
		"$output_dir/napc.h", LIBNAPC_SOURCE_FILES_DIR
	);

	if (napphp::fs_isFile("$output_dir/__tests__/__tests__.h")) {
		$file_contents .= "\n\n";
		$file_contents .= napphp::fs_readFileString(
			"$output_dir/__tests__/__tests__.h"
		);
	}

	napphp::fs_writeFileStringAtomic(
		"$output_dir/napc.h",
		$file_contents
	);
};
