<?php

return function($keys) {
	echo napcdoc::createHTMLElement("a", [
		"class" => "section"
	], $keys["label"]);
};
