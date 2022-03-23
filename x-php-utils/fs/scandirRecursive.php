<?php

function XPHPUtils__fs_scandirRecursive($root_path, $path = "", &$ret = NULL) {
	if ($ret === NULL) $ret = [];
	if (!strlen($path)) $path = $root_path;

	$entries = scandir($path);

	foreach ($entries as $entry) {
		if ($entry === "." || $entry === "..") continue;

		$abs_path = "$path/$entry";
		$rel_path = substr($abs_path, strlen($root_path) + 1);

		if (is_dir($abs_path)) {
			XPHPUtils__fs_scandirRecursive($root_path, $abs_path, $ret);

			$ret[] = [
				"abs_path" => $abs_path,
				"rel_path" => $rel_path,
				"basename" => $entry,
				"type" => "dir"
			];
		} else {
			$ret[] = [
				"abs_path" => $abs_path,
				"rel_path" => $rel_path,
				"basename" => $entry,
				"type" => "file"
			];
		}
	}

	return $ret;
}

return function($path) {
	return XPHPUtils__fs_scandirRecursive($path);
};
