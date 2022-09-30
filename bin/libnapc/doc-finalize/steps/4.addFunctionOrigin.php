<?php

return function($args, &$context) {
	$output = &$context["output"];
	$statistics = &$output["statistics"];

	$statistics["fn_missing_origins"] = 0;

	foreach ($output["definitions"] as $definition_name => &$definition) {
		if ($definition["type"] !== "fn") continue;

		$fn_colored = napphp::terminal_colorString($definition_name, "yellow");

		$return_type = napphp::str_replace(
			$definition["return"]["type"], "*", "\*"
		);

		$search_term = "";

		// do not add space for pointer return types
		if (napphp::str_endsWith($return_type, "*")) {
			$search_term = "$return_type$definition_name(";
		} else {
			$search_term = "$return_type $definition_name(";
		}

		$grep_output_file = napphp::tmp_createFile();

		napphp::shell_execute(
			"grep", [
				"cwd" => LIBNAPC_SOURCE_FILES_DIR,
				"args" => [
					"-nr",
					$search_term,
					"--include",
					"*.c",
					"."
				],
				"stdout" => $grep_output_file
			]
		);

		$grep_output = napphp::fs_file($grep_output_file);
		$raw_origin = NULL;

		if (sizeof($grep_output) === 1) {
			$raw_origin = $grep_output[0];
		}

		if ($raw_origin === NULL) {
			fwrite(STDERR, "Was not able to determine origin of function '$fn_colored'.\n");

			$statistics["fn_missing_origins"]++;

			continue;
		}

		$tmp = napphp::str_split($raw_origin, ":", 3);

		if (sizeof($tmp) !== 3) {
			$statistics["fn_missing_origins"]++;

			fwrite(STDERR, "Was not able to determine origin of function '$fn_colored'.\n");

			continue;
		}

		$definition["origin"] = [
			"path" => $tmp[0],
			"line" => (int)$tmp[1]
		];
	}
};
