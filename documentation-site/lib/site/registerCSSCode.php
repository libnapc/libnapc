<?php

return function($code = NULL) {
	static $napcdoc_css_code = [];

	if ($code !== NULL) {
		$napcdoc_css_code[] = $code;
	}

	return $napcdoc_css_code;
};
