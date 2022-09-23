<?php

function libnapc_deploy_downloadFile($url) {
	$local_file = napphp::tmp_createFile();

	fwrite(STDOUT, "Downloading '$url'\n");

	napphp::shell_execute(
		"curl", [
			"args" => [
				$url,
				"-o",
				$local_file,
				"--fail",
				"--silent"
			]
		]
	);

	return $local_file;
}

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
		$dry_run = $args["flags"]["dry-run"] ?? false;

		$context = [
			"dry_run" => $dry_run,
			"build_constants" => napphp::fs_readFileJSON(
				LIBNAPC_BUILD_FILES_DIR."/build_constants.json"
			)
		];

		command_runSteps("deploy", $args, $context);
	}
];
