<?php

return function($text) {
	$text = htmlspecialchars($text);

	return napcdoc::formatting_replaceBackticks($text);
};
