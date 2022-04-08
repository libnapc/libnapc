<?php

return function($src, $attributes = []) {
	$image_attributes = [
		"src" => napcdoc::fs_base64Image(__DIR__."/../../assets/image/$src")
	];

	foreach ($attributes as $_name => $_value) {
		$image_attributes[$_name] = $_value;
	}

	return napcdoc::html_createElement("img", $image_attributes);
};
