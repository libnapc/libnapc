<?php

chdir(__DIR__."/../__tests__/");

`rm -rf _processed`;

mkdir("_processed");

function get_modules() {
	$entries = scandir(".");
	$modules = [];

	foreach ($entries as $entry) {
		// ignore dot files
		if (substr($entry, 0, 1) === ".") continue;
		// ignore entries that start with _
		if (substr($entry, 0, 1) === "_") continue;

		$modules[] = $entry;
	}

	return $modules;
}

function get_module_tests($module) {
	$output = shell_exec("find $module -name '*.c'");
	$lines = explode("\n", $output);
	$files = [];

	foreach ($lines as $line) {
		$file = trim($line);
		$file_path = realpath($file);

		if (is_file($file_path)) {
			$files[] = $file_path;
		}
	}

	return $files;
}

function process_module_test_file($module, $test_file, &$context) {
	$lines = file($test_file);

	$test_path = "$module/".basename($test_file);
	$new_file_contents = "#include <napc.h>\n";

	if (!array_key_exists($module, $context["tests"])) {
		$context["tests"][$module] = [];
	}

	foreach ($lines as $line) {
		if (substr($line, 0, strlen("TEST_CASE(\"")) === "TEST_CASE(\"") {
			$description = substr($line, strlen("TEST_CASE(\""));
			$description = substr($description, 0, strpos($description, "\")"));

			$test_case_id = $context["last_test_case_id"] + 1;

			$fn_name = "PV_napc_${module}__testCase$test_case_id";

			$new_file_contents .= "void $fn_name(void) {\n";
			$new_file_contents .= "    napc_unmute();\n";
			$new_file_contents .= "    napc_puts(\"[$test_path] $description ... \");\n";
			$new_file_contents .= "    napc_mute();\n";

			$context["tests"][$module][] = $fn_name;

			++$context["last_test_case_id"];
		} else {
			$new_file_contents .= $line;
		}
	}

	$file_name = "_processed/${module}_".basename($test_file);

	file_put_contents($file_name, $new_file_contents);
}

$modules = get_modules();
$context = [
	"last_test_case_id" => 0,
	"tests" => []
];

foreach ($modules as $module) {
	$module_tests = get_module_tests($module);

	foreach ($module_tests as $module_test) {
		process_module_test_file(
			$module, $module_test, $context
		);
	}
}

function create_tests_file($context) {
	$file = "#include <napc.h>\n";
	$header_file  = "#if !defined(NAPC_ALL_TESTS_FILE_h)\n";
	$header_file .= "    #define NAPC_ALL_TESTS_FILE_h\n\n";
	$header_file .= "    #if defined(__cplusplus)\n";
	$header_file .= "        extern \"C\" {\n";
	$header_file .= "    #endif\n";

	$modules = array_keys($context["tests"]);

	// fn prototypes
	foreach ($context["tests"] as $module => $tests) {
		foreach ($tests as $test) {
			$file .= "void $test(void);\n";
		}
	}

	foreach ($modules as $module) {
		$file .= "void napc_${module}__runTests(void) {\n";
		$header_file .= "    void napc_${module}__runTests(void);\n";

		foreach ($context["tests"][$module] as $test) {
			$file .= "    $test();";
			$file .= " napc_unmute();";
			$file .= " napc_puts(\"passed!\\n\");";
			$file .= " napc_mute();\n";
		}

		$file .= "    napc_unmute();\n";
		$file .= "    napc_puts(\"All ${module} tests have passed!\\n\");\n";
		$file .= "    napc_mute();\n";

		$file .= "}\n";
	}

	$file .= "void napc_runAllTests(void) {\n";
	$header_file .= "\n    void napc_runAllTests(void);\n";

	foreach ($modules as $module) {
		$file .= "    napc_${module}__runTests();\n";
	}

	$file .= "    napc_unmute();\n";
	$file .= "    napc_puts(\"\\n\\nAll tests successfully passed! :-)\\n\\n\");\n";

	$file .= "}\n";

	$header_file .= "    #if defined(__cplusplus)\n";
	$header_file .= "        }\n";
	$header_file .= "    #endif\n";

	$header_file .= "#endif\n";

	file_put_contents("__tests__.c", $file);
	file_put_contents("__tests__.h", $header_file);
}

create_tests_file($context);
