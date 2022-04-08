<?php

if (
	array_key_exists("general_info", $__keys) && 
	array_key_exists("changelog", $__keys["general_info"])
) {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Changelog"
	]);

	echo '<div class="flex-table changelog">';
	echo '	<div class="flex-table-row">';
	echo '		<div class="flex-table-row-cell">Version</div>';
	echo '		<div class="flex-table-row-cell">Date</div>';
	echo '		<div class="flex-table-row-cell">Change</div>';
	echo '	</div>';

	foreach ($__keys["general_info"]["changelog"] as $entry) {
		echo '<div class="flex-table-row">';
		echo '	<div class="flex-table-row-cell c_type">'.$entry["version"].'</div>';
		echo '	<div class="flex-table-row-cell">'.$entry["date"].'</div>';
		echo '	<div class="flex-table-row-cell">'.$entry["change"].'</div>';
		echo '</div>';
	}

	echo '</div>';
	echo '</div>';
}
