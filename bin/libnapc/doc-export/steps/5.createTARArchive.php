<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];

	napphp::proc_changeWorkingDirectory(
		$output_dir, function() use ($context) {
			napphp::shell_execTransparently(
				"fakeroot", [
					"tar", "-czvf", $context["output_tar"], "."
				]
			);
		}
	);
};
