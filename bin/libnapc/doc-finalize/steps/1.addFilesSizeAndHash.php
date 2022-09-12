<?php

return function($args, &$context) {
	$context["output"]["files"] = [];

	foreach ($context["downloadable_files"] as $file => $absolute_path) {
		$context["output"]["files"][$file] = [
			"checksum" => napphp::fs_hashFile($absolute_path, "sha256"),
			"size" => filesize($absolute_path)
		];
	}
};
