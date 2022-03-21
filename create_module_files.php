<?php

fwrite(STDERR, "Name: ");

$module_name = trim(fgets(STDIN));

$module_path = __DIR__."/src/$module_name";

if (is_dir($module_path)) {
	fprintf(STDERR, "Module already exists.\n");
	exit(1);
}

fwrite(STDERR, "HAL? (y|n) ");
$answer = trim(fgets(STDIN));
$wants_HAL = $answer === "y" || $answer === "yes";


mkdir($module_path);
mkdir("$module_path/_private");
mkdir("$module_path/public");

if ($wants_HAL) {
	mkdir("$module_path/HAL");
	mkdir("$module_path/HAL/linux");
	mkdir("$module_path/HAL/arduino");
}

$header_guard_name = str_replace("-", "_", $module_name);
$header_guard_name = strtoupper($header_guard_name)."_h";

if ($wants_HAL) {
	file_put_contents("$module_path/_private/_$module_name.h", "#if !defined(PV_$header_guard_name)\n\t#define PV_$header_guard_name\n\n\t#include <$module_name/$module_name.h>\n\t#include <$module_name/HAL/HAL.h>\n\n#endif\n");
} else {
	file_put_contents("$module_path/_private/_$module_name.h", "#if !defined(PV_$header_guard_name)\n\t#define PV_$header_guard_name\n\n\t#include <$module_name/$module_name.h>\n\n#endif\n");
}

file_put_contents("$module_path/$module_name.h", "#if !defined($header_guard_name)\n\t#define $header_guard_name\n\n\t#include <libnapc.h>\n#endif\n");

if ($wants_HAL) {
	file_put_contents("$module_path/HAL/HAL.h", "#if !defined(HAL_$header_guard_name)\n\t#define HAL_$header_guard_name\n\n\t#include <$module_name/$module_name.h>\n#endif\n");
}
