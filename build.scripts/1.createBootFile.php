<?php

return function() {
	$entries = XPHPUtils::fs_scandirRecursive("src");
	$boot_files = array_filter($entries, function($entry) {
		return $entry["type"] === "file" && substr($entry["basename"], -5, 5) === ".boot";
	});

	$boot_functions = array_map(function($entry) {
		list($priority, $fn_name, $unused) = explode(".", $entry["basename"], 3);

		return [
			"priority" => (int)$priority,
			"fn_name" => $fn_name
		];
	}, $boot_files);

	usort($boot_functions, function($a, $b) {
		if ($a["priority"] === $b["priority"]) return 0;

		if ($a["priority"] > $b["priority"]) {
			return 1;
		}

		return -1;
	});

	$boot_functions_str  = "";
	$boot_functions_str .= "/**\n";
	$boot_functions_str .= " * Warning: this file was auto generated.\n";
	$boot_functions_str .= " */\n";
	$boot_functions_str .= "void napc_puts(const char *str);\n";

	foreach ($boot_functions as $boot_function) {
		$fn_name = $boot_function["fn_name"];

		$boot_functions_str .= "void $fn_name(void);\n";
	}

	$boot_functions_str .= "\nvoid libnapc_callBootFunctions(void) {\n";

	foreach ($boot_functions as $boot_function) {
		$fn_name = $boot_function["fn_name"];
		$pri = $boot_function["priority"];

		fwrite(STDERR, "Added $fn_name() [boot,pri=$pri]\n");

		$boot_functions_str .= "    $fn_name();\n";
		$boot_functions_str .= "    napc_puts(\"[boot] called $fn_name (pri=$pri)\\n\");\n";
		$boot_functions_str .= "\n";
	}

	$boot_functions_str .= "    napc_puts(\"[boot] calling into napc_main() now.\\n\");\n";

	$boot_functions_str .= "}\n";

	file_put_contents(
		"build/boot_functions.c", $boot_functions_str
	);
};
