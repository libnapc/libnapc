<?php

return function($args, &$context) {
	$getPath = require LIBNAPC_PROJECT_ROOT_DIR."/.dependencies/getPath.php";

	$valgrind_bin = $getPath("valgrind");

	napphp::shell_execute(
		$valgrind_bin, [
			"args" => [
				"--leak-check=full",
				"--show-reachable=yes",
				"--error-exitcode=1",
				$context["executable"]
			]
		]
	);
};
