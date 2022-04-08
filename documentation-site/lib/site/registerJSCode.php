<?php

return function($code = NULL) {
	static $napcdoc_js_code = [];

	if ($code !== NULL) {
		$napcdoc_js_code[] = $code;
	}

	return $napcdoc_js_code;
};
