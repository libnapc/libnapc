<?php

return function($template_file, $__keys = []) {
	$load = function() use ($template_file, $__keys) {
		ob_start();

		require __DIR__."/../../template/$template_file.php";

		return ob_get_clean();
	};

	return $load();
};
