<?php

require_once __DIR__."/../load-napphp.php";

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

	$output_file = napphp::tmp_createFile();

	napphp::shell_execute(
		"curl", [
			"args" => [
				"--silent",
				"$base_url/download/$file_name",
				"-o",
				$output_file
			]
		]
	);

	$local_hash = napphp::fs_hashFile($output_file, "sha256");

	if ("$local_hash" !== "$file->checksum") {
		fwrite(STDERR, "Checksum mismatch detected!\n");
		fwrite(STDERR, "Expected hash (in metadata.xml) : '".$file->checksum."'\n");
		fwrite(STDERR, "Actual hash                     : '$local_hash'\n");
		exit(1);
	}
}

fwrite(STDERR, "All checksums ok!\n");
