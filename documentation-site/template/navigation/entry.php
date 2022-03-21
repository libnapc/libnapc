<?php

return function($keys) {
	$label = napcdoc::createHTMLElement("span", [
		"class" => "label"
	], $keys["label"]);

	$brief = isset($keys["brief"]) && strlen($keys["brief"]) ? napcdoc::createHTMLElement("span", [
		"class" => "brief"
	], $keys["brief"]) : "";

	$a_element_content = napcdoc::createSVGElement($keys["icon"], 18, 18);

	if (isset($keys["second_icon"]) && strlen($keys["second_icon"])) {
		$second_icon_class = $keys["second_icon_class"] ?? "";

		$a_element_content .= napcdoc::createSVGElement($keys["second_icon"], 12, 12, [
			"class" => "napcdoc-svg-image second-icon $second_icon_class"
		]);
	}

	$a_element_content .= napcdoc::createHTMLElement("div", [
		"class" => "label-and-brief"
	], $label.$brief);

	$a_attributes = [
		"href" => napcdoc::documentation_fixLink($keys["link"])
	];

	$classes = [];

	if (isset($keys["active"])) {
		if ($keys["active"]) {
			$classes[] = "active";
		}
	} else if (isset($keys["slim"])) {
		if ($keys["slim"]) {
			$classes[] = "slim";
		}
	}

	if (isset($keys["deprecated"]) && $keys["deprecated"]) {
		$classes[] = "deprecated";
	}

	if (isset($keys["data-attributes"])) {
		foreach ($keys["data-attributes"] as $name => $value) {
			$a_attributes["data-$name"] = $value;
		}
	}

	if (isset($keys["id"])) {
		$id = $keys["id"];

		if (isset($keys["id_prefix"])) {
			$id = $keys["id_prefix"].$id;
		}

		$a_attributes["id"] = $id;
	}

	$a_attributes["class"] = implode(" ", $classes);

	echo napcdoc::createHTMLElement("a", $a_attributes, $a_element_content);
};
