<?php

return function($args, &$context) {
	napphp::shell_execute(
		"fakeroot", [
			"cwd" => $context["output_dir"],
			"args" => [
				"tar",
				"-czvf",
				$context["output_tar"],
				"."
			]
		]
	);
};
