<?php

return function($args, &$context) {
	$boot_files = napphp::arr_filter($context["source_entries"], function($entry) {
		if ($entry["type"] !== "file") {
			return false;
		}

		return napphp::str_endsWith($entry["basename"], ".boot");
	});

	$boot_functions = napphp::arr_map($boot_files, function($entry) {
		list($priority, $fn_name, $unused) = explode(".", $entry["basename"], 3);

		return [
			"priority" => (int)$priority,
			"fn_name" => $fn_name
		];
	});

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

	napphp::fs_writeFileStringAtomic(
		$context["output_dir"]."/boot_functions.c", $boot_functions_str
	);
};
