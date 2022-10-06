<?php

if (strlen($__keys["general_info"]["example"] ?? "")) {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Example" // Example(s)
	]);

	echo napcdoc::site_renderTemplateFile("component/content-box", [
		"type" => "example-usage",
		"code_language" => "c",
		"code" => $__keys["general_info"]["example"]
	]);

	echo '</div>';
}
