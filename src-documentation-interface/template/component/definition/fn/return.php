<?php

if ($__keys["type"] === "fn") {
	if (strlen($__keys["return"]["description"])) {
		echo '<div class="module-section">';
		echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
			"label" => "Returns"
		]);

		echo napcdoc::format_singleLine($__keys["return"]["description"]);
		echo '</div>';
	}

	/*else if ($__keys["return"]["type"] === "void") {
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Returns"
		]);

		echo '<p><i>This function does not return anything.</i></p>';
	}*/
}
