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
		echo napcdoc::site_renderTemplateFile("component/content-box", [
			"type" => "warning",
			"content" => $warning
		]);
	}
}
