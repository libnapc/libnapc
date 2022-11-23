<?php

return function($args, &$context) {
	$init_files = napphp::arr_filter($context["source_entries"], function($entry) {
		if ($entry["type"] !== "file") {
			return false;
		}

		return napphp::str_endsWith($entry["basename"], ".init");
	});

	$init_functions = napphp::arr_map($init_files, function($entry) {
		list($priority, $fn_name, $unused) = explode(".", $entry["basename"], 3);

		return [
			"priority" => (int)$priority,
			"fn_name" => $fn_name
		];
	});

	usort($init_functions, function($a, $b) {
		if ($a["priority"] === $b["priority"]) return 0;

		if ($a["priority"] > $b["priority"]) {
			return 1;
		}

		return -1;
	});

	$init_function_str  = "";
	$init_function_str .= "/**\n";
	$init_function_str .= " * Warning: this file was auto generated.\n";
	$init_function_str .= " */\n";
	$init_function_str .= "void libnapc_puts(const char *str);\n";

	foreach ($init_functions as $boot_function) {
		$fn_name = $boot_function["fn_name"];

		$init_function_str .= "void $fn_name(void);\n";
	}

	$init_function_str .= "static unsigned char _initialised = 0;\n";

	$init_function_str .= "\nvoid libnapc_init(void) {\n";
	$init_function_str .= "    if (_initialised != 0) return;\n\n";

	foreach ($init_functions as $boot_function) {
		$fn_name = $boot_function["fn_name"];
		$pri = $boot_function["priority"];

		fwrite(STDOUT, "Added $fn_name() [libnapc/init,pri=$pri]\n");

		$init_function_str .= "    $fn_name();\n";
		$init_function_str .= "    libnapc_puts(\"[libnapc/init] called $fn_name (pri=$pri)\\n\");\n";
		$init_function_str .= "\n";
	}

	$init_function_str .= "    libnapc_puts(\"[libnapc/init] done\\n\");\n\n";
	$init_function_str .= "    _initialised = 1;\n";

	$init_function_str .= "}\n";

	napphp::fs_writeFileStringAtomic(
		$context["output_dir"]."/init.c", $init_function_str
	);
};
