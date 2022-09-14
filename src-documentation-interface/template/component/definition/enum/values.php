<?php

if ($__keys["type"] === "type" && $__keys["kind"] === "enum") {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Values"
	]);

	echo '<div class="flex-table enum-values">';

	/*
	echo '	<div class="flex-table-row">';
	echo '		<div class="flex-table-row-cell">Name</div>';
	echo '		<div class="flex-table-row-cell">Description</div>';
	echo '	</div>';
	*/

	foreach ($__keys["values"] as $value) {
		echo '<div class="flex-table-row">';
		echo '	<div class="flex-table-row-cell">';
		echo '		<span style="font-family: \'PT Mono\';color:rgb(203,203,203)">'.$value["name"].'</span>';
		echo '	</div>';
		echo '	<div class="flex-table-row-cell">';
		echo '		'.napcdoc::format_singleLine($value["description"]);
		echo '	</div>';
		echo '</div>';
	}

	echo '</div>';
	echo '</div>';
}
