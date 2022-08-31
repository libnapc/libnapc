<?php

return function() {
	$entries = napphp::fs_scandirRecursive("__tests__");
	$test_files = napphp::arr_filter($entries, function($entry) {
		return $entry["type"] === "file";
	});

	$context = [
		"last_test_case_id" => 0,
		"tests" => []
	];

	foreach ($test_files as $test_file) {
		$module = napphp::str_split($test_file["relative_path"], "/", 2)[0];

		if (!napphp::arr_keyExists($context["tests"], $module)) {
			$context["tests"][$module] = [];

			napphp::fs_mkdir("build/__tests__/$module");
		}

		$lines = file($test_file["path"]);

		$new_file_contents = "#include <napc.h>\n";

		foreach ($lines as $line) {
			if (napphp::str_startsWith($line, "TEST_CASE(\"")) {
				$description = substr($line, strlen("TEST_CASE(\""));
				$description = substr($description, 0, strpos($description, "\")"));

				$test_case_id = $context["last_test_case_id"] + 1;

				$fn_name = "PV_napc_${module}__testCase$test_case_id";

				$new_file_contents .= "void $fn_name(void) {\n";
				$new_file_contents .= "    napc_unmute();\n";
				$new_file_contents .= "    napc_puts(\"[".$test_file["relative_path"]."] $description ... \");\n";
				$new_file_contents .= "    napc_mute();\n";

				$context["tests"][$module][] = $fn_name;

				++$context["last_test_case_id"];
			} else {
				$new_file_contents .= $line;
			}

			$dest_path = napphp::str_replace($test_file["relative_path"], "/", "_");

			napphp::fs_writeFileStringAtomic(
				"build/__tests__/$module/$dest_path", $new_file_contents
			);
		}
	}

	napphp::fs_writeFileJSONAtomic("build/__tests__/map.json", $context);
};
