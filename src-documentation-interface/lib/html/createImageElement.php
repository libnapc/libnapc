<?php

return function($src, $attributes = []) {
	$base64 = base64_encode(
		napphp::fs_readFileString(__DIR__."/../../assets/image/$src")
	);

	$image_url = "data:image/png;base64,$base64";

	$image_attributes = [
		"src" => $image_url
	];

	foreach ($attributes as $_name => $_value) {
		$image_attributes[$_name] = $_value;
	}

	return napcdoc::html_createElement("img", $image_attributes);
};
