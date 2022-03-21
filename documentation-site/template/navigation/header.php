<?php

return function($keys) {
	foreach ($keys["navigation"]["header"]["menu"] as $section => $links) {
		/*echo napcdoc::createHTMLElement("a", [
			"class" => "section"
		], $section);*/

		foreach ($links as $link) {
			$icon = napcdoc::createSVGElement($link["icon"], 16, 16);

			echo napcdoc::createHTMLElement("a", [
				"href" => $link["link"]
			], $icon.$link["label"]);
		}
	}

	echo "<div class=\"search\">";

	echo napcdoc::createHTMLElement("a", [
		"class" => "section"
	], "Search");

	echo napcdoc::createHTMLElement("input", [
		"id" => "napcdoc-local-search-input",
		"placeholder" => "Please activate JavaScript"
	]);

	echo "</div>";
};
