<?php

return function($text) {
	$text = htmlspecialchars($text);

	return napcdoc::format_replaceBackticks($text);
};
