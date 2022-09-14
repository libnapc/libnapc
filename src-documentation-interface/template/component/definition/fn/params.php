<?php

if (array_key_exists("params", $__keys)) {
	if (sizeof($__keys["params"])) {
		echo '<div class="module-section">';
		echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
			"label" => "Parameter"
		]);

		echo "<div class=\"flex-table fn-params\">";

		foreach ($__keys["params"] as $parameter) {
			echo '<div class="flex-table-row">';
			echo '	<div class="flex-table-row-cell">';
			echo '		<span style="font-family: \'PT Mono\';color:rgb(203,203,203)">'.$parameter["name"].'</span>';
			echo '	</div>';

			echo '	<div class="flex-table-row-cell">';
			echo '		<div>'.napcdoc::format_singleLine($parameter["description"]).'</div>';
			echo '	</div>';
			echo '</div>';
		}

		echo '</div>';
		echo '</div>';
	}
	/*else {
		echo '<p><i>This function does not take any parameter.</i></p>';
	}*/
}

