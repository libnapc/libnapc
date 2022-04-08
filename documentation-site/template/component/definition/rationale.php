<?php

if (strlen($__keys["general_info"]["rationale"] ?? "")) {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Rationale"
	]);

	echo napcdoc::format_multiLine($__keys["general_info"]["rationale"]);
	echo '</div>';
}
