<?php

require_once __DIR__."/../3rd/parsedown-1.7.4/Parsedown.php";

return function($text) {
	static $Parsedown = NULL;

	if (!$Parsedown) {
		$Parsedown = new Parsedown();
	}

	return napcdoc::html_createElement("div", [
		"class" => "markdown"
	], $Parsedown->text($text));
};
