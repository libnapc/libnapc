<?php

require_once __DIR__."/../x-php-utils/load.php";

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

function assert_readenv($env_name) {
	$value = getenv($env_name);

	if (!$value) {
		fwrite(STDERR, "Failed to read environment variable '$env_name'\n");
		exit(2);
	}

	return $value;
}


function upload_to_remote_host($src_path, $dst_path) {
	global $ssh_identity_file;

	$upload_username = assert_readenv("LIBNAPC_DEPLOY_USER");
	$upload_hostname = assert_readenv("LIBNAPC_DEPLOY_HOST");

	$scp_source        = escapeshellarg($src_path);
	$scp_identity_file = escapeshellarg($ssh_identity_file);
	$scp_destination   = escapeshellarg(
		"$upload_username@$upload_hostname:$dst_path"
	);

	$scp_flags = "-o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null";

	XPHPUtils::shell_assertSystemCall("scp $scp_flags -i $scp_identity_file $scp_source $scp_destination");
}

$upload_username = assert_readenv("LIBNAPC_DEPLOY_USER");

upload_to_remote_host(__DIR__."/verified.css", "/home/$upload_username/www/$release_version/verified.css");
