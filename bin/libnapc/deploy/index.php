<?php

return [
	"description" => [
		"Deploy to github and official website.",
		"",
		"Make sure that the repository's secrets are properly set:",
		"",
		"  - SSH-Key used for commit signing (.secrets/keys/commit_signing/id_rsa)",
		"  - SSH-Key used to push commits to github repositories (.secrets/keys/github_push/id_rsa)",
		"  - SSH-Key used to upload files to web-hosting (.secrets/keys/site_deploy/id_rsa)",
		"  - Github Access Token (.secrets/github_access_token) to set default branches (post-deploy)"
	],

	"depends_on" => [
		"bundles",
		"documentation.tar.gz",
		"build_constants.json"
	],

	"run" => function($args) {
		$build_constants = napphp::fs_readFileJSON(LIBNAPC_BUILD_FILES_DIR."/build_constants.json");

		if (!napphp::str_startsWith($build_constants["RELEASE_VERSION"], "v")) {
			$ver = $build_constants["RELEASE_VERSION"];

			throw new CommandError(
				"Refusing to deploy invalid release version '$ver'."
			);
		}

		$dry_run = $args["flags"]["dry-run"] ?? false;
		$deploy_args = [];

		if ($dry_run) {
			array_push($deploy_args, "--dry-run");
		}

		$release_archive_file = napphp::tmp_createFile(".tar.gz");

		napphp::shell_execute(
			"curl", [
				"args" => [
					"https://static.nap-software.com/github/libnapc/software-release.tar.gz",
					"-o",
					$release_archive_file
				]
			]
		);

		$archive_files = napphp::tmp_createDirectory();

		napphp::shell_execute(
			"tar", [
				"args" => [
					"-xzvf",
					$release_archive_file,
					"-C",
					$archive_files
				],
				"stdout" => "/dev/null"
			]
		);

		$exit_code = napphp::shell_execute(
			"$archive_files/index.php", [
				"cwd" => LIBNAPC_PROJECT_ROOT_DIR,
				"args" => $deploy_args,
				"allow_non_zero_exit_code" => true
			]
		);

		if ($exit_code !== 0) {
			throw new CommandError("software-release script failed with exit code '$exit_code'.");
		}
	}
];
