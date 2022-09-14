<?php

return function() {
	if (!array_key_exists("global_napcdoc_request_path", $GLOBALS)) {
		throw new Exception("Call napcdoc::http_setRequestPath first.");
	}

	$path = $GLOBALS["global_napcdoc_request_path"];

	while (strpos($path, "//") !== false) {
		$path = str_replace("//", "/", $path);
	}

	if (substr($path, 0, 1) === "/") {
		$path = substr($path, 1);
	}

	if (!strlen($path)) {
		return "index.html";
	}

	$query_start_pos = strpos($path, "?");

	if ($query_start_pos !== false) {
		return substr($path, 0, $query_start_pos);
	}

	return $path;
};
