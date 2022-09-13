<?php

// todo: check php version
$NAPPHP_LOAD_PATH = getenv("NAPPHP_LOAD_PATH");

if (!is_file($NAPPHP_LOAD_PATH)) {
	fwrite(STDERR, "Either NAPPHP_LOAD_PATH is not set, or does not exist.\n");
	exit(2);
}

require_once $NAPPHP_LOAD_PATH;

fwrite(STDERR, "[debug] Using napphp version v".napphp::info_getVersion()."\n");

napphp::set("tmp_dir", __DIR__."/../tmp.d/");

$release_version = getenv("LIBNAPC_RELEASE_VERSION");

if (!strlen($release_version)) {
	fwrite(STDERR,"Please set environment variable 'LIBNAPC_RELEASE_VERSION' to the version you want to check.\n");
	exit(2);
} else if (substr($release_version, 0, 1) !== "v") {
	fwrite(STDERR, "Invalid LIBNAPC_RELEASE_VERSION, must begin with 'v'\n");
	exit(2);
}

$base_url = "https://libnapc.nap-software.com/$release_version";

fwrite(STDERR, "Downloading 'metadata.xml'\n");

$metadata_xml = file_get_contents("$base_url/metadata.xml");
$metadata = new SimpleXMLElement($metadata_xml);

foreach ($metadata->release_files->release_file as $file) {
	$file_name = $file->name;

	fwrite(STDERR, "Downloading '$file_name'\n");

	$curl_url = escapeshellarg("$base_url/download/$file_name");
	$output_file = __DIR__."/tmp/$file_name";
	$curl_output_file = escapeshellarg($output_file);

	napphp::shell_execTransparently("curl --silent $curl_url -o $curl_output_file");

	$local_hash = hash_file("sha256", $output_file);

	if (!$local_hash) {
		fwrite(STDERR, "Failed to calculate local hash\n");
		exit(1);
	}

	if ("$local_hash" !== "$file->checksum") {
		fwrite(STDERR, "Checksum mismatch detected!\n");
		fwrite(STDERR, "Expected hash (in metadata.xml) : '".$file->checksum."'\n");
		fwrite(STDERR, "Actual hash                     : '$local_hash'\n");
		exit(1);
	}
}

fwrite(STDERR, "All checksums ok!\n");
