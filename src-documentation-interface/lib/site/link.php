<?php

return function($link) {
	$pieces = explode("/", napcdoc::http_getRequestPath());
	array_shift($pieces);

	return str_repeat("./../", sizeof($pieces)).$link;
};
