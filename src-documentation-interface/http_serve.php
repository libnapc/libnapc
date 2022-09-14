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



$page_generator = require __DIR__."/page_generator.php";

$request_headers = [];

foreach (getallheaders() as $header_name => $header_value) {
	$request_headers[strtolower($header_name)] = $header_value;
}

if (napphp::str_endsWith($_SERVER["REQUEST_URI"], ".css")) {
	header("Content-Type: text/css;charset=UTF-8");
} else if (napphp::str_endsWith($_SERVER["REQUEST_URI"], ".js")) {
	header("Content-Type: text/javascript;charset=UTF-8");
} else if (napphp::str_endsWith($_SERVER["REQUEST_URI"], ".xml")) {
	header("Content-Type: text/xml;charset=UTF-8");
} else {
	header("Content-Type: text/html;charset=UTF-8");
}

echo $page_generator(
	$_SERVER["REQUEST_URI"],
	$request_headers
);
