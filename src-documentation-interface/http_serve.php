<?php

require_once __DIR__."/../load-napphp.php";

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
