<?php

return function($name, $attributes, $content = false) {
	$ret  = "<$name";

	if (sizeof($attributes)) {
		$ret .= " ";
	}

	foreach ($attributes as $_name => $_value) {
		if ($_name === "class" && is_array($_value)) {
			$ret .= "$_name=\"".implode(" ", $_value)."\" ";
		} else {
			$ret .= "$_name=\"$_value\" ";
		}
	}

	if ($content === false) {
		return $ret."/>";
	}

	$ret .= ">$content</$name>";

	return $ret;
};
