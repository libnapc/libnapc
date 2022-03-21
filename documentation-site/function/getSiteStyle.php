<?php

return function() {
	$ret = "";

	foreach (napcdoc::assets_getCSSAssets() as $style) {
		$ret .= $style;
	}

	$ret .= "\n/** SASS **/\n";

	foreach (napcdoc::assets_getSASSAssets() as $style) {
		$ret .= $style;
	}

	return $ret;
};
