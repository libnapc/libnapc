<?php

return function($args, &$context) {
	if (napphp::arr_keyExists($args["flags"], "no-tests")) {
		return;
	}

	$origin_comment = <<<ORIGIN_COMMENT
/**
 * This file was automatically created by bin/libnapc/preprocess/steps/4.createTestsHeaderAndSourceFile.php
 */

ORIGIN_COMMENT;

	$file  = "$origin_comment";
	$file .= "#include <libnapc.h>\n";

	$header_file  = $origin_comment;
	$header_file .= "#if !defined(LIBNAPC_ALL_TESTS_FILE_h)\n";
	$header_file .= "    #define LIBNAPC_ALL_TESTS_FILE_h\n\n";
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
		$c_friendly_module = libnapc_preprocess_CFriendlyModuleName($module);

		$file .= "void libnapc_${c_friendly_module}__runTests(void) {\n";
		$header_file .= "    void libnapc_${c_friendly_module}__runTests(void);\n";

		foreach ($context["tests"][$module] as $test) {
			$file .= "    $test();";
			$file .= " libnapc_unmute();";
			$file .= " libnapc_puts(\"passed!\\n\");";
			$file .= " libnapc_mute();\n";
		}

		$file .= "    libnapc_unmute();\n";
		$file .= "    libnapc_puts(\"All ${module} tests have passed!\\n\");\n";
		$file .= "    libnapc_mute();\n";

		$file .= "}\n";
	}

	$file .= "void libnapc_runAllTests(void) {\n";
	$header_file .= "\n    void libnapc_runAllTests(void);\n";

	foreach ($modules as $module) {
		$c_friendly_module = libnapc_preprocess_CFriendlyModuleName($module);

		$file .= "    libnapc_${c_friendly_module}__runTests();\n";
	}

	$file .= "    libnapc_unmute();\n";
	$file .= "    libnapc_puts(\"\\n\\nAll tests successfully passed! :-)\\n\\n\");\n";

	$file .= "}\n";

	$header_file .= "    #if defined(__cplusplus)\n";
	$header_file .= "        }\n";
	$header_file .= "    #endif\n";

	$header_file .= "#endif\n";

	$output_dir = $context["output_dir"];

	napphp::fs_writeFileStringAtomic(
		"$output_dir/__tests__/__tests__.c", $file
	);

	napphp::fs_writeFileStringAtomic(
		"$output_dir/__tests__/__tests__.h",
		$header_file
	);
};
