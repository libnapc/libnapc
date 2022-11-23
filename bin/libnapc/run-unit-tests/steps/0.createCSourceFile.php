<?php

return function($args, &$context) {
	$c_source_code = <<<CODE
#include <libnapc.h>

int main(int argc, const char **argv) {
	NAPC_IGNORE_VALUE(argc);
	NAPC_IGNORE_VALUE(argv);

	libnapc_init();

	libnapc_printf("libnapc version is %s\\n", libnapc_version());

	napc_runAllTests();
}
CODE;

	$c_source_file = napphp::tmp_createFile(".c");
	$output_file = napphp::tmp_createFile();

	napphp::fs_writeFileStringAtomic($c_source_file, $c_source_code);

	$context["c_source_file"] = $c_source_file;
};
