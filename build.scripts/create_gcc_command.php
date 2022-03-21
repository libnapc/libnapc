<?php

chdir(__DIR__."/../");

$output = shell_exec("find src -name '*.c' && find __tests__/_processed  __tests__/__tests__.c -name '*.c'");

$lines = explode("\n", $output);
$gcc_command = "gcc -Wall -Wextra -Wpedantic -I./src/ test.c -o run \\\n";

foreach ($lines as $line) {
	$line = trim($line);

	if (!strlen($line)) continue;

	$file_path = realpath(__DIR__."/../$line");

	$gcc_command .= "    $file_path \\\n";
}

echo $gcc_command;

system($gcc_command);
