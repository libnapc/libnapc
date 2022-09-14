<?php

return function($sass_bin, $file) {
	$proc = proc_open(
		escapeshellcmd($sass_bin)." ".escapeshellarg($file),
		[
			["pipe", "r"],
			["pipe", "w"],
			["pipe", "w"]
		],
		$pipes
	);

	$exit_code = -1;

	while (true) {
		$status = proc_get_status($proc);

		if (!$status["running"]) {
			$exit_code = $status["exitcode"];
			break;
		}

		usleep(5E3);
	}

	$stdout = stream_get_contents($pipes[1]);
	$stderr = stream_get_contents($pipes[2]);
	fclose($pipes[1]); fclose($pipes[2]);
	proc_close($proc);

	if ($exit_code !== 0) {
		return [false, $stderr];
	}

	return [true, $stdout];
};
