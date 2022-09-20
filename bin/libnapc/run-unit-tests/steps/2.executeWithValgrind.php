<?php

return function($args, &$context) {
	napphp::shell_execute(
		"valgrind", [
			"args" => [
				"--leak-check=full",
				"--show-reachable=yes",
				"--error-exitcode=1",
				$context["executable"]
			]
		]
	);
};
