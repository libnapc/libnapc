<?php

function exec_or_die($command) {
	system($command, $exit_code);

	if ($exit_code !== 0) {
		throw new Error("Failed to execute command.");
	}

	clearstatcache();
}
