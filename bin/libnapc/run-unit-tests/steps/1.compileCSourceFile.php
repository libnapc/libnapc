<?php

return function($args, &$context) {
	$output_file = napphp::tmp_createFile();

	napphp::shell_execTransparently("gcc", [
		"-Wall", "-Wpedantic", "-Werror", "-Wextra",
		"-L/".$context["library_path"],
		"-I/".$context["include_path"],
		$context["c_source_file"],
		"-lnapc",
		"-o", $output_file
	]);

	$context["executable"] = $output_file;
};
