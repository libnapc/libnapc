<?php

if (strlen($__keys["general_info"]["example"] ?? "")) {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Example Usage"
	]);

	echo '<pre class="code hljs">'.$__keys["general_info"]["example"].'</pre>';
	echo '</div>';
}
