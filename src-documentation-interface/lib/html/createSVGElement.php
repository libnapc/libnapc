<?php

return function($name, $width, $height, $attributes = []) {
	$svg = file_get_contents(__DIR__."/../../assets/svg/$name.svg");

	$svg = preg_replace('/width="([0-9]+)"/', 'width="'.$width.'"', $svg);
	$svg = preg_replace('/height="([0-9]+)"/', 'height="'.$height.'"', $svg);

	// remove svg headers
	$svg_start = strpos($svg, "<svg");

	if ($svg_start !== false) {
		$svg = substr($svg, $svg_start);
	}

	$flex  = 'display:flex;align-items:center;justify-content:center;';
	$flex .= 'flex-grow:0;flex-shrink:0';

	$svg_attributes = [
		"style" => 'width:'.$width.'px;height:'.$height.'px;'.$flex,
		"class" => "napcdoc-svg-image"
	];

	foreach ($attributes as $name => $value) {
		$svg_attributes[$name] = $value;
	}

	return napcdoc::html_createElement(
		"div", $svg_attributes,
		$svg
	);
}

?>
