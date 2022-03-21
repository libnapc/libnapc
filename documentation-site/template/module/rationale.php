<?php

return function($definition) {
	if (strlen($definition["general_info"]["rationale"] ?? "")) {
		echo '<div class="module-section">';
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Rationale"
		]);

		echo napcdoc::formatting_multiLine($definition["general_info"]["rationale"]);
		echo '</div>';
	}
};
