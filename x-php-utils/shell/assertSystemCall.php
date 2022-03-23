<?php

return function($command, $args = []) {
	$args = array_map("escapeshellarg", $args);

	system(
		$command." ".implode(" ", $args),
		$exit_code
	);

	if ($exit_code !== 0) {
		exit(1);
	}
};
