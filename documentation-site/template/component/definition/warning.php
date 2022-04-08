<?php

if (!isset($__keys["general_info"]["warning"])) {
	return;
}

if (is_array($__keys["general_info"]["warning"]) || strlen($__keys["general_info"]["warning"])) {
	if (!is_array($__keys["general_info"]["warning"])) {
		$warnings = [$__keys["general_info"]["warning"]];
	} else {
		$warnings = $__keys["general_info"]["warning"];
	}

	foreach ($warnings as $warning) {
		echo '<div class="warning-box">';
		echo napcdoc::html_createSVGElement("alert", 24, 24);
		echo '	<div>';
		echo '		'.napcdoc::format_singleLine($warning);
		echo '	</div>';
		echo '</div>';
	}
}

