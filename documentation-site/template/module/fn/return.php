<?php

return function($definition) {
	if ($definition["type"] === "fn") {
		if (strlen($definition["return"]["description"])) {
			echo '<div class="module-section">';
			echo napcdoc::renderFile("module/section-title", [
				"label" => "Returns"
			]);

			echo napcdoc::formatting_singleLine($definition["return"]["description"]);
			echo '</div>';
		}

		/*else if ($definition["return"]["type"] === "void") {
			echo napcdoc::renderFile("module/section-title", [
				"label" => "Returns"
			]);

			echo '<p><i>This function does not return anything.</i></p>';
		}*/
	}
};
