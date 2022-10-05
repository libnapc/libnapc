<?php

return function($macro_name) {
	$napc = napcdoc::site_getDocumentation();

	$macro = $napc["definitions"][$macro_name];

	$ret  = '<pre class="code-inside-content-box">';
	$ret .= "#define $macro_name(";

	$params = $macro["params"];

	foreach ($params as $i => $param) {
		$is_last_param = !array_key_exists($i + 1, $params);

		if ($is_last_param) {
			$ret .= $param["name"];
		} else {
			$ret .= $param["name"].", ";
		}
	}

	$ret .= ")</pre>";

	return napcdoc::html_createElement("span",
		["class" => "c-macro"],
		$ret
	);
};
