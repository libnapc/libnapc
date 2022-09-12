<?php

return function($args, &$context) {
	$c_source_code = <<<CODE
#include <napc.h>

void napc_app_setup(const char *platform) {
	napc_printf("Platform is %s\\n", platform);
	napc_printf("libnapc version is %s\\n", napc_version());

	napc_runAllTests();
}

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	return false;
}
CODE;

	$c_source_file = napphp::tmp_createFile(".c");
	$output_file = napphp::tmp_createFile();

	napphp::fs_writeFileStringAtomic($c_source_file, $c_source_code);

	$context["c_source_file"] = $c_source_file;
};
