<?php

return function($keys) {
	foreach ($keys["navigation"]["header"]["menu"] as $section => $links) {
		foreach ($links as $link) {
			$icon = napcdoc::createSVGElement($link["icon"], 18, 18);

			echo napcdoc::createHTMLElement("a", [
				"href" => $link["link"],
				"class" => "menu-link"
			], $icon.$link["label"]);
		}
	}

	foreach ($keys["navigation"]["entries"] as $section => $entries) {
		if (!sizeof($entries)) continue;

		echo napcdoc::renderFile("navigation/section", [
			"label" => $section
		]);

		foreach ($entries as $entry) {
			$entry["id_prefix"] = "mobile_";

			echo napcdoc::renderFile("navigation/entry", $entry);
		}
	}
};
