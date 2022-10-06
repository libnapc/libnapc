<?php

if ($__keys["is_part_of_HAL"] ?? false) {
	$type = $__keys["type"];

	if ($type === "fn") {
		$type = "function";
	}

	echo napcdoc::site_renderTemplateFile("component/content-box", [
		"type" => "hal",
		"content" => "This $type is part of the hardware abstraction layer."
	]);
}
