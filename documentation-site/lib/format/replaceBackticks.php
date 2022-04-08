<?php

return function($text) {
	$napc = napcdoc::site_getDocumentation();

	$backticks = napcdoc::util_extractBackticksFromString($text);
	$formatted_text = $backticks["text"];

	foreach ($backticks["map"] as $key => $value) {
		$replace_with = "???";

		$is_function = substr($value, -2, 2) === "()";

		if ($is_function) {
			$value = substr($value, 0, strlen($value) - 2);
		}

		/* boolean */
		if ($value === "true" || $value === "false") {
			$replace_with = "<span class=\"bt-pill bool-$value\">$value</span>";
		}
		/* definition */
		else if (array_key_exists($value, $napc["definitions"])) {
			$definition = $napc["definitions"][$value];

			$definition_link = napcdoc::site_link(
				"definition/".napcdoc::doc_getModuleByDefinitionName(
					$value
				)."/$value.html#$value"
			);

			$popover = 'data-popover="'.$value.'"';

			//napcdoc::documentation_registerPopover($value);

			switch ($definition["type"]) {
				case "type":
					$replace_with = "<a $popover href=\"$definition_link\" class=\"bt-pill type\">$value</a>";
				break;

				case "fn":
					$replace_with = "<a $popover href=\"$definition_link\" class=\"bt-pill fn\">$value()</a>";
				break;
			}
		} else {
			$replace_with = "<span class=\"bt-pill text\">$value</span>"; // "<code class=\"inline\">$value</code>";//
		}

		$formatted_text = str_replace($key, $replace_with, $formatted_text);
	}

	return $formatted_text;
};
