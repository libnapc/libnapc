<?php

return function($name, $attributes, $content = false) {
	$ret  = "<$name";

	if (sizeof($attributes)) {
		$ret .= " ";
	}

	foreach ($attributes as $_name => $_value) {
		$ret .= "$_name=\"$_value\" ";
	}

	if ($content === false) {
		return $ret."/>";
	}

	$ret .= ">$content</$name>";

	return $ret;
};
