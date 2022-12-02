<?php

return function($args, &$context) {
	$getPath = require LIBNAPC_PROJECT_ROOT_DIR."/.dependencies/getPath.php";

	$fakeroot_bin = $getPath("fakeroot");

	napphp::shell_execute(
		$fakeroot_bin, [
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
