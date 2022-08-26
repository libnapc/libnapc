<?php

require_once __DIR__."/../x-php-utils/load.php";

$release_version = getenv("LIBNAPC_RELEASE_VERSION");

if (!strlen($release_version)) {
	fwrite(STDERR,"Please set environment variable 'LIBNAPC_RELEASE_VERSION' to the version you want to check.\n");
	exit(2);
}

$base_url = "https://libnapc.nap-software.com/v$release_version";

fwrite(STDERR, "Downloading 'metadata.xml'\n");

$metadata_xml = file_get_contents("$base_url/metadata.xml");
$metadata = new SimpleXMLElement($metadata_xml);

foreach ($metadata->release_files->release_file as $file) {
	$file_name = $file->name;

	fwrite(STDERR, "Downloading '$file_name'\n");

	$curl_url = escapeshellarg("$base_url/download/$file_name");
	$output_file = __DIR__."/tmp/$file_name";
	$curl_output_file = escapeshellarg($output_file);

	XPHPUtils::shell_assertSystemCall("curl --silent $curl_url -o $curl_output_file");

	$local_hash = hash_file("sha256", $output_file);

	if (!$local_hash) {
		fwrite(STDERR, "Failed to calculate local hash\n");
		exit(1);
	}

	if ($local_hash !== $file->checksum) {
		fwrite(STDERR, "Checksum mismatch detected!\n");
		fwrite(STDERR, "Expected hash (in metadata.xml) : ".$file->checksum."\n");
		fwrite(STDERR, "Actual hash                     : $local_hash\n");
		exit(1);
	}
}

fwrite(STDERR, "All checksums ok!\n");
