<?php

if (strlen($__keys["general_info"]["notes"] ?? "")) {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Notes"
	]);

	echo napcdoc::format_multiLine($__keys["general_info"]["notes"]);
	echo '</div>';
}
