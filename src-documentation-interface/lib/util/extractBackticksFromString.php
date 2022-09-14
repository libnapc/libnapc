<?php

return function($text) {
	$out = "";
	$open = false;
	$tmp = "";
	$map = [];

	for ($i = 0; $i < strlen($text); ++$i) {
		$ch = $text[$i];

		if ($ch === "`") {
			if ($open) {
				$identifier = md5($i);

				$map[$identifier] = $tmp;

				$out .= $identifier;
			} else {
				// start of backtick section
				$tmp = "";
			}

			$open = !$open;
		} else if ($open) {
			// inside backtick, collect text
			$tmp .= $ch;
		} else {
			// outside backtick, append to output
			$out .= $ch;
		}
	}

	return [
		"map" => $map,
		"text" => $out
	];
};
