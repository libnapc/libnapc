<?php

return function($request_path) {
	$_404_page = napphp::fs_readFileString(__DIR__."/../content/404.html");

	if ($request_path === "/404.html") {
		$_404_page = napphp::str_replace(
			$_404_page, [
				"%%TITLE%%",
				"%%INFO_TEXT%%",
				"%%OVERRIDE_H1_STYLE%%",
				"%%BUTTON%%"
			], [
				"404",
				"The page you're looking for could not be found :(",
				"",
				"<a href=\"https://libnapc.nap-software.com\">Go back to start page</a>"
			]
		);
	} else {
		$_404_page = napphp::str_replace(
			$_404_page, [
				"%%TITLE%%",
				"%%INFO_TEXT%%",
				"%%OVERRIDE_H1_STYLE%%",
				"%%BUTTON%%"
			], [
				"ERROR",
				"Requested resource ($request_path) was not found.",
				"font-size: 100px; color: red; background: unset; -webkit-background-clip: unset; -webkit-text-fill-color: unset;",
				""
			]
		);
	}

	return $_404_page;
};
