<?php

return function($definition) {
	if (strlen($definition["general_info"]["notes"] ?? "")) {
		echo '<div class="module-section">';
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Notes"
		]);

		echo napcdoc::formatting_multiLine($definition["general_info"]["notes"]);
		echo '</div>';
	}
};
