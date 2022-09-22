<?php

require_once __DIR__."/../load-napphp.php";

if (sizeof($argv) !== 2) {
	fwrite(STDERR, "Usage: add_checksums_verified_icon.php <ssh-identity-file>\n");
	exit(2);
}

$ssh_identity_file = $argv[1];
$release_version = getenv("LIBNAPC_RELEASE_VERSION");

if (!strlen($release_version)) {
	fwrite(STDERR,"Please set environment variable 'LIBNAPC_RELEASE_VERSION' to the version you want to check.\n");
	exit(2);
} else if (substr($release_version, 0, 1) !== "v") {
	fwrite(STDERR, "Invalid LIBNAPC_RELEASE_VERSION, must begin with 'v'\n");
	exit(2);
}

$upload_hostname = napphp::proc_getEnvironmentVariable("LIBNAPC_SSH_SITE_DEPLOY_HOST");
$upload_username = napphp::proc_getEnvironmentVariable("LIBNAPC_SSH_SITE_DEPLOY_USER");
/*
napphp::ssh_uploadToRemote(
	$upload_hostname,
	$upload_username,
	$ssh_identity_file,
	__DIR__."/verified.css",
	"/home/$upload_username/www/$release_version/verified.css"
);
*/
