<?php

require_once __DIR__."/../load-napphp.php";

$page_generator = require __DIR__."/page_generator.php";

$request_headers = [];

foreach (getallheaders() as $header_name => $header_value) {
	$request_headers[strtolower($header_name)] = $header_value;
}

$request_path = $_SERVER["REQUEST_URI"];

if (strpos($request_path, "?") !== false) {
	$position = strpos($request_path, "?");

	$request_path = substr($request_path, 0, $position);
}

$response = $page_generator(
	$request_path,
	$request_headers
);

if (napphp::arr_keyExists($response, "headers")) {
	foreach ($response["headers"] as $header_name => $header_value) {
		header("$header_name: $header_value");
	}
}

echo $response["body"];
