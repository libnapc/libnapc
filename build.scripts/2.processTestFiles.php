<?php

return function() {
	$entries = XPHPUtils::fs_scandirRecursive("__tests__");
	$test_files = array_filter($entries, function($entry) {
		return $entry["type"] === "file";// && substr($entry["basename"], -5, 5) === ".boot";
	});

	$context = [
		"last_test_case_id" => 0,
		"tests" => []
	];

	foreach ($test_files as $test_file) {
		$module = explode("/", $test_file["rel_path"], 2)[0];

		if (!array_key_exists($module, $context["tests"])) {
			$context["tests"][$module] = [];

			mkdir("build/__tests__/$module", 0777, true);
		}

		$lines = file($test_file["abs_path"]);

		$new_file_contents = "#include <napc.h>\n";

		foreach ($lines as $line) {
			if (substr($line, 0, strlen("TEST_CASE(\"")) === "TEST_CASE(\"") {
				$description = substr($line, strlen("TEST_CASE(\""));
				$description = substr($description, 0, strpos($description, "\")"));

				$test_case_id = $context["last_test_case_id"] + 1;

				$fn_name = "PV_napc_${module}__testCase$test_case_id";

				$new_file_contents .= "void $fn_name(void) {\n";
				$new_file_contents .= "    napc_unmute();\n";
				$new_file_contents .= "    napc_puts(\"[".$test_file["rel_path"]."] $description ... \");\n";
				$new_file_contents .= "    napc_mute();\n";

				$context["tests"][$module][] = $fn_name;

				++$context["last_test_case_id"];
			} else {
				$new_file_contents .= $line;
			}

			$dest_path = str_replace("/", "_", $test_file["rel_path"]);

			file_put_contents(
				"build/__tests__/$module/$dest_path", $new_file_contents
			);
		}
	}

	file_put_contents("build/__tests__/map.json", json_encode(
		$context, JSON_PRETTY_PRINT
	));
};
