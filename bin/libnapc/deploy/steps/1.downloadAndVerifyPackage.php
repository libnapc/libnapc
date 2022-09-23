<?php

return function($args, &$context) {
	$release_archive_file = libnapc_deploy_downloadFile(
		"https://static.nap-software.com/github/libnapc/software-release.tar.gz"
	);

	$release_archive_file_checksum = libnapc_deploy_downloadFile(
		"https://static.nap-software.com/github/libnapc/software-release.tar.gz.sha256"
	);

	$expected_checksum = trim(
		napphp::fs_readFileString($release_archive_file_checksum)
	);

	$actual_checksum = napphp::fs_hashFile($release_archive_file, "sha256");

	if ($expected_checksum !== $actual_checksum) {
		throw new CommandError(
			"Failed to verify checksum of software-release.tar.gz:\n".
			"Expected checksum (sha256): $expected_checksum\n".
			"Actual checksum (sha256)  : $actual_checksum"
		);
	}

	fwrite(STDOUT, "Checksum checks out!\n");

	$context["software_release_archive"] = $release_archive_file;
};
