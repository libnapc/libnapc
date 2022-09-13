#!/usr/bin/env php
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

/**
 * This script creates the documentation.
 */
define("SERVER_ROOT_URL", "http://localhost:9999");

napphp::proc_changeWorkingDirectory(__DIR__);

$output_dir = napphp::tmp_createDirectory();
$web_tmp_dir = napphp::tmp_createDirectory();

napphp::proc_changeWorkingDirectory($output_dir);


function download($path) {
	global $web_tmp_dir;

	fwrite(STDERR, "Downloading $path\n");

	napphp::fs_mkdir(dirname($path));

	$opts = [
		"http" => [
			"header" => "x-napdoc-set-tmp-directory: $web_tmp_dir\r\n"
		]
	];

	$context = stream_context_create($opts);

	$contents = file_get_contents(SERVER_ROOT_URL."/$path", false, $context);

	if (!$contents) {
		fwrite(STDERR, "Failed to download $path\n");

		exit(1);
	}

	napphp::fs_writeFileStringAtomic($path, $contents);
}

$napc = napphp::fs_readFileJSON(__DIR__."/content/napc.json");

foreach ($napc["modules"] as $module_name => $module_definitions) {
	if ($module_name === "app") continue;

	download("module/$module_name.html");

	foreach ($module_definitions as $definition) {
		$definition_name = substr($definition, 2);

		download(
			"definition/$module_name/$definition_name.html"
		);
	}
}

$documents = napphp::fs_scandirRecursive(__DIR__."/content/documents");

foreach ($documents as $document) {
	if ($document["type"] !== "file") continue;

	$filename = basename($document["relative_path"]);

	if (!napphp::str_endsWith($filename, ".md")) continue;

	download("document/$filename.html");
}

download("api.html");
download("debug.html");
download("releases.html");
download("home.html");
download("documentation/index.html");

download("site.css");
download("site.js");

download("metadata.xml");
download("index.html");

$output_tar_file = napphp::tmp_createFile(".tar.gz");

napphp::shell_execTransparently(
	"tar -czvf ".escapeshellarg($output_tar_file)." ."
);

napphp::fs_rename(
	$output_tar_file, __DIR__."/../build_files/documentation.tar.gz"
);
