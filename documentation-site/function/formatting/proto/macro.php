<?php

return function($macro_name) {
	$napc = napcdoc::documentation_get();

	$macro = $napc["definitions"][$macro_name];

	$ret  = '<pre class="code">';
	$ret .= "#define $macro_name(";

	$params = $macro["params"];

	foreach ($params as $i => $param) {
		$is_last_param = !array_key_exists($i + 1, $params);

		if ($is_last_param) {
			if ($macro["variadic"]) {
				$ret .= "...";
			} else {
				$ret .= $param["name"];
			}
		} else {
			$ret .= $param["name"].", ";
		}
	}

	$ret .= ")</pre>";

	return napcdoc::createHTMLElement("span",
		["class" => "c-macro"],
		$ret
	);
};
