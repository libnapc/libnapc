<?php

return function($args, &$context) {
	fwrite(STDOUT, "Unpacking software-release.tar.gz\n");

	$archive_files = napphp::tmp_createDirectory();

	napphp::shell_execute(
		"tar", [
			"args" => [
				"-xzvf",
				$context["software_release_archive"],
				"-C",
				$archive_files
			],
			"stdout" => "/dev/null"
		]
	);

	$context["archive_files"] = $archive_files;

	fwrite(STDOUT, "Unpacked software-release.tar.gz\n");
};
