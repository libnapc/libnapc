#!/usr/bin/env php
<?php

$start_file = $argv[1];
$context = __DIR__."/../src/";

$included_headers = [];

function process_file($file, $context, $indent_level = 0) {
	global $included_headers;

	$lines = file($file);
	$ret = "";

	$indentation = str_repeat("    ", $indent_level);

	foreach ($lines as $line) {
		$trimmed_line = trim($line);

		if (substr($trimmed_line, 0, 8) === "#include") {
			$include_expr = trim(substr($trimmed_line, 8));
			$include_path = substr($include_expr, 1);
			$include_path = substr($include_path, 0, strpos($include_path, ">"));

			$absolute_include_path = $context.$include_path;

			$ret .= "\n/* original: $trimmed_line */\n";

			if (is_file($absolute_include_path)) {
				$real_include_path = realpath($absolute_include_path);

				if (!array_key_exists($real_include_path, $included_headers)) {
					$ret .= process_file($absolute_include_path, $context, $indent_level + 1);
				} else {
					$ret .= "/* header file already included */\n";
				}

				$included_headers[$real_include_path] = 1;
			} else {
				$ret .= $indentation.trim($line);
			}
		} else {
			$ret .= $indentation.$line;
		}
	}

	return $ret;
}

echo process_file($start_file, $context);
