<?php

return function($definition) {
	if ($definition["type"] === "type" && $definition["kind"] === "struct") {
		echo '<div class="module-section">';
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Members"
		]);

		echo '<div class="flex-table struct-members">';

		/*
		echo '	<div class="flex-table-row">';
		echo '		<div class="flex-table-row-cell">Name</div>';
		echo '		<div class="flex-table-row-cell">Description</div>';
		echo '	</div>';
		*/

		foreach ($definition["fields"] as $field) {
			echo '<div class="flex-table-row">';
			echo '	<div class="flex-table-row-cell">';
			echo '	<span style="font-family: \'PT Mono\';color:rgb(203,203,203)">'.$field["name"].'</span>';
			echo '	</div>';
			echo '	<div class="flex-table-row-cell">';
			echo '		<div>'.napcdoc::formatting_singleLine($field["description"]).'</div>';
			echo '	</div>';
			echo '</div>';
		}
		echo '</div>';
		echo '</div>';
	}
};
