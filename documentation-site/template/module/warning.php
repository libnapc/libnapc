<?php

return function($definition) {
	if (!isset($definition["general_info"]["warning"])) {
		return;
	}

	if (is_array($definition["general_info"]["warning"]) || strlen($definition["general_info"]["warning"])) {
		if (!is_array($definition["general_info"]["warning"])) {
			$warnings = [$definition["general_info"]["warning"]];
		} else {
			$warnings = $definition["general_info"]["warning"];
		}

		foreach ($warnings as $warning) {
			echo '<div class="warning-box">';
			echo napcdoc::createSVGElement("alert", 24, 24);
			echo '	<div>';
			echo '		'.napcdoc::formatting_singleLine($warning);
			echo '	</div>';
			echo '</div>';
		}
	}
};
