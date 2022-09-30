<?php

return function($text) {
	$text = htmlspecialchars($text);

	$ret = "";

	foreach (explode("\n\n", $text) as $line) {
		$ret .= "<p>".napcdoc::format_replaceBackticks($line)."</p>";
	}

	return $ret;
};
