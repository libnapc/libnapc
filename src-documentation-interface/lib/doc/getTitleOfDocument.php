<?php

return function($document_name) {
	$lines = napphp::fs_file(
		__DIR__."/../../content/documents/$document_name.md"
	);

	$first_line = trim($lines[0]);

	$title = substr(
		$first_line, strpos($first_line, "#") + 1
	);

	return trim($title);
};
