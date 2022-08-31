<?php

return function() {
	$context = napphp::fs_readFileJSON("build/__tests__/map.json");

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

	napphp::fs_writeFileStringAtomic("build/__tests__/__tests__.c", $file);
	napphp::fs_writeFileStringAtomic("build/__tests__/__tests__.h", $header_file);
};
