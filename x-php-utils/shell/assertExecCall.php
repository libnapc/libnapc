<?php

return function($command, $args = []) {
	$args = array_map("escapeshellarg", $args);

	exec(
		$command." ".implode(" ", $args), $output, $exit_code
	);

	if ($exit_code !== 0) {
		exit(1);
	}

	return $output;
};
