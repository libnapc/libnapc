#!/usr/bin/env php
<?php

require_once __DIR__."/x-php-utils/load.php";

chdir(__DIR__);

$url = getenv("LIBNAPC_DEPLOY_URL");

$post = [
	"LIBNAPC_DEPLOY_KEY"      => getenv("LIBNAPC_DEPLOY_KEY"),
	"LIBNAPC_GIT_BRANCH"      => XPHPUtils::git_getCurrentBranch(),
	"LIBNAPC_GIT_HEAD"        => XPHPUtils::git_getHEADHash(),
	"LIBNAPC_RELEASE_VERSION" => XPHPUtils::libnapc_getReleaseVersion()
];

foreach ([
	"doc.tar.gz",
	"libnapc-arduino.zip",
	"libnapc-x86_64.a",
	"libnapc-aarch64.a",
	"napc.h"
] as $file) {
	$post_key = str_replace(".", "_", $file);

	$file_path = __DIR__."/dist/$file";

	$post[$post_key] = curl_file_create($file_path);

	$post[$post_key."_sha256"] = hash_file("sha256", $file_path);
}

$ch = curl_init();

curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_POST, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, $post);

curl_setopt($ch, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);

$resp = curl_exec($ch);

$response_code = (int)curl_getinfo($ch, CURLINFO_HTTP_CODE);

$error_msg = "";

if (curl_errno($ch)) {
	$error_msg = curl_error($ch);
}

curl_close($ch);

if (strlen($error_msg)) {
	fwrite(STDERR, "curl error: $error_msg\n");
	exit(1);
} else if ($response_code !== 200) {
	fwrite(STDERR, "Error\n");
	exit(1);
}
