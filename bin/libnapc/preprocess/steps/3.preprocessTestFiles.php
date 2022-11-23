<?php

return function($args, &$context) {
	if (napphp::arr_keyExists($args["flags"], "no-tests")) {
		return;
	}

	$origin_comment = <<<ORIGIN_COMMENT
/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */

ORIGIN_COMMENT;

	$output_dir = $context["output_dir"];

	$test_files = napphp::arr_filter($context["test_source_entries"], function($entry) {
		return $entry["type"] === "file";
	});

	$context["tests"] = [];
	$last_test_case_id = 0;

	foreach ($test_files as $test_file) {
		$module = napphp::str_split($test_file["relative_path"], "/", 2)[0];
		$c_friendly_module = libnapc_preprocess_CFriendlyModuleName($module);

		if (!napphp::arr_keyExists($context["tests"], $module)) {
			$context["tests"][$module] = [];
		}

		$lines = napphp::fs_file($test_file["path"]);

		$new_file_contents  = $origin_comment;
		$new_file_contents .= "#include <libnapc.h>\n";

		foreach ($lines as $line) {
			if (napphp::str_startsWith($line, "TEST_CASE(\"")) {
				$description = substr($line, strlen("TEST_CASE(\""));
				$description = substr($description, 0, strpos($description, "\")"));

				$test_case_id = $last_test_case_id + 1;

				$fn_name = "PV_napc_${c_friendly_module}__testCase$test_case_id";

				$new_file_contents .= "void $fn_name(void) {\n";
				$new_file_contents .= "    libnapc_unmute();\n";
				$new_file_contents .= "    libnapc_puts(\"[".$test_file["relative_path"]."] $description ... \");\n";
				$new_file_contents .= "    libnapc_mute();\n";

				$context["tests"][$module][] = $fn_name;

				++$last_test_case_id;
			} else {
				$new_file_contents .= $line;
			}

			$dest_path = napphp::str_replace($test_file["relative_path"], "/", "_");

			napphp::fs_writeFileStringAtomic(
				"$output_dir/__tests__/$module/$dest_path", $new_file_contents
			);
		}
	}
};
