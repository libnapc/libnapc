<?php

return function($args, &$context) {
	napphp::shell_execTransparently(
		"valgrind", [
			"--leak-check=full",
			"--show-reachable=yes",
			"--error-exitcode=1",
			$context["executable"]
		]
	);
};
