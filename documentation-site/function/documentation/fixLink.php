<?php

return function($link) {
	$pieces = explode("/", $_SERVER["REQUEST_URI"]);
	$pieces = array_filter($pieces, "strlen");

	if (sizeof($pieces) === 2) {
		return "../$link";
	}

	return "./$link";
};
