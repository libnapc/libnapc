<?php

return function($file, $keys) {
	ob_start();

	$template = require __DIR__."/../template/$file.php";

	$template($keys);

	return ob_get_clean();
};
