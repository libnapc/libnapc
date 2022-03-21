<?php

function napcdoc__scandirRecursive($root_path, $path = "", &$ret = NULL) {
	if ($ret === NULL) $ret = [];
	if (!strlen($path)) $path = $root_path;

	$entries = scandir($path);

	foreach ($entries as $entry) {
		if ($entry === "." || $entry === "..") continue;

		$abs_path = "$path/$entry";
		$rel_path = substr($abs_path, strlen($root_path) + 1);

		if (is_dir($abs_path)) {
			napcdoc__scandirRecursive($root_path, $abs_path, $ret);
		} else {
			$ret[] = [$abs_path, $rel_path, $entry];
		}
	}

	return $ret;
}

return function($path) {
	return napcdoc__scandirRecursive($path);
};
