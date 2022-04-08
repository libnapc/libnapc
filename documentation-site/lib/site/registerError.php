<?php

return function($error = NULL) {
	static $napcdoc_errors = [];

	if ($error !== NULL) {
		$napcdoc_errors[] = $error;
	}

	return $napcdoc_errors;
};
