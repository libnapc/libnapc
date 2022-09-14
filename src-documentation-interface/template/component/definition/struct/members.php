<?php

if ($__keys["type"] === "type" && $__keys["kind"] === "struct") {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Members"
	]);

	echo '<div class="flex-table struct-members">';

	/*
	echo '	<div class="flex-table-row">';
	echo '		<div class="flex-table-row-cell">Name</div>';
	echo '		<div class="flex-table-row-cell">Description</div>';
	echo '	</div>';
	*/

	foreach ($__keys["fields"] as $field) {
		echo '<div class="flex-table-row">';
		echo '	<div class="flex-table-row-cell">';
		echo '	<span style="font-family: \'PT Mono\';color:rgb(203,203,203)">'.$field["name"].'</span>';
		echo '	</div>';
		echo '	<div class="flex-table-row-cell">';
		echo '		<div>'.napcdoc::format_singleLine($field["description"]).'</div>';
		echo '	</div>';
		echo '</div>';
	}
	echo '</div>';
	echo '</div>';
}
