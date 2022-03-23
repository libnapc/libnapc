<?php

return function($command, $args = []) {
	$args = array_map("escapeshellarg", $args);

	return exec(
		$command." ".implode(" ", $args)
	);
};
