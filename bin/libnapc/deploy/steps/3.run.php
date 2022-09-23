<?php

return function($args, &$context) {
	fwrite(STDOUT, "Running software-release/index.php\n");

	$archive_files = $context["archive_files"];

	$deploy_args = [];

	if ($context["dry_run"]) {
		array_push($deploy_args, "--dry-run");
	}

	$exit_code = napphp::shell_execute(
		"$archive_files/index.php", [
			"cwd" => LIBNAPC_PROJECT_ROOT_DIR,
			"args" => $deploy_args,
			"allow_non_zero_exit_code" => true
		]
	);

	if ($exit_code !== 0) {
		throw new CommandError(
			"software-release script failed with exit code '$exit_code'."
		);
	}
};
