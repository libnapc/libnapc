<?php

chdir(__DIR__."/../");

$output = shell_exec("find src/ -name '*.boot'");
$lines = explode("\n", $output);
$boot_functions = [];

foreach ($lines as $line) {
	$file = basename(trim($line));

	if (!strlen($file)) continue;

	list($priority, $fn_name, $unused) = explode(".", $file, 3);

	$boot_functions[] = [
		"priority" => (int)$priority,
		"fn_name" => $fn_name
	];
}

usort($boot_functions, function($a, $b) {
	if ($a["priority"] === $b["priority"]) return 0;

	if ($a["priority"] > $b["priority"]) {
		return 1;
	}

	return -1;
});

$boot_functions_str  = "";
$boot_functions_str .= "/**\n";
$boot_functions_str .= " * Warning: this file was auto generated by create_boot_file.php!\n";
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

file_put_contents("src/boot_functions.c", $boot_functions_str);

fwrite(STDERR, "Created src/boot_functions.c\n");