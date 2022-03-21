<?php

return function() {
	$path = $_SERVER["REQUEST_URI"];

	while (strpos($path, "//") !== false) {
		$path = str_replace("//", "/", $path);
	}

	if (substr($path, 0, 1) === "/") {
		$path = substr($path, 1);
	}

	return $path;
};
