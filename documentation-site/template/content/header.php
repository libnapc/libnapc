<?php

return function($keys) {
	$svg_html_attributes = [];

	if (isset($keys["content_header"]["data-attributes"])) {
		foreach ($keys["content_header"]["data-attributes"] as $name => $value) {
			$svg_html_attributes["data-$name"] = $value;
		}
	}

	if ($keys["content_header"]["icon"] !== false) {
		echo napcdoc::createSVGElement(
			$keys["content_header"]["icon"], 26, 26, $svg_html_attributes
		);
	}

	$second_icon = $keys["content_header"]["second_icon"] ?? "";
	$second_icon_class = $keys["content_header"]["second_icon_class"] ?? "";

	if (strlen($second_icon)) {
		echo napcdoc::createSVGElement(
			$keys["content_header"]["second_icon"], 20, 20, [
				"class" => "napcdoc-svg-image second-icon $second_icon_class"
			]
		);
	}

	$div_content  = napcdoc::createHTMLElement("h1", [], $keys["content_header"]["title"]);

	if (strlen($keys["content_header"]["description"])) {
		$div_content .= napcdoc::createHTMLElement("span", [], $keys["content_header"]["description"]);
	}

	echo napcdoc::createHTMLElement("div", [
		"class" => "title-and-description"
	], $div_content);
};
