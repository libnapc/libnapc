<?php

return function($keys) {
	foreach ($keys["navigation"]["entries"] as $section => $entries) {
		if (!sizeof($entries)) continue;

		echo napcdoc::renderFile("navigation/section", [
			"label" => $section
		]);

		echo '<div class="section-delimiter"></div>';

		foreach ($entries as $entry) {
			echo napcdoc::renderFile("navigation/entry", $entry);
		}
	}
};
