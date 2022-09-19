<?php

return [
	"description" => [
		"Prepare for deployment to github and official website.",
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
		"documentation.tar.gz"
	],

	"creates" => "deployment-data",

	"run" => function() {
		$git_repositories_dir = napphp::tmp_createDirectory();

		$git_repositories = [
			"libnapc/libnapc-arduino-releases",
			"libnapc/libnapc-linux-releases",
			"libnapc/libnapc-documentation"
		];

		$ssh_signing_key = LIBNAPC_PROJECT_ROOT_DIR."/.secrets/keys/commit_signing/id_rsa";
		$ssh_github_push_key  = LIBNAPC_PROJECT_ROOT_DIR."/.secrets/keys/github_push/id_rsa";

		if (!napphp::fs_isAFile($ssh_signing_key)) {
			throw new CommandError("Private commit signing key at '.secrets/keys/commit_signing/id_rsa' is missing.");
		} else if (!napphp::fs_isAFile($ssh_github_push_key)) {
			throw new CommandError("Private github push key at '.secrets/keys/github_push/id_rsa' is missing.");
		}

		$git_local_config = [
			"user.email"      => "github-bot@nap.software",
			"user.name"       => "NAP-Software (bot)",
			"gpg.format"      => "ssh",
			"user.signingkey" => $ssh_signing_key,
			"core.sshCommand" => "ssh -i ".escapeshellarg($ssh_github_push_key)
		];

		foreach ($git_repositories as $git_repository) {
			napphp::fs_mkdir("$git_repositories_dir/$git_repository");

			$repo_colored = napphp::terminal_colorString($git_repository, "cyan");

			fwrite(STDERR, "Initializing git repository '$repo_colored'\n");

			napphp::proc_changeWorkingDirectory("$git_repositories_dir/$git_repository", function() use ($git_repository, $git_local_config) {
				napphp::shell_execTransparently(
					"git", [
						"clone",
						"git@github.com:$git_repository.git",
						"."
					]
				);

				napphp::shell_execTransparently("git", ["checkout", "main"]);
				napphp::shell_execTransparently("git", ["rm", "-rf", "."]);
				napphp::shell_execTransparently("git", ["clean", "-fxd"]);

				foreach ($git_local_config as $name => $value) {
					napphp::shell_execTransparently(
						"git", [
							"config", $name, $value
						]
					);
				}
			});
		}

		napphp::fs_rename(
			$git_repositories_dir, LIBNAPC_BUILD_FILES_DIR."/deployment-data/"
		);
	}
];
