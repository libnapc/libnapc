<?php

if (isset($__keys["general_info"]["deprecated"]) && $__keys["general_info"]["deprecated"]) {
	$type = $__keys["type"];

	if ($type === "fn") $type = "function";

	$replace_with_text = "";

	if (isset($__keys["general_info"]["deprecated_replacement"])) {
		$replacement = $__keys["general_info"]["deprecated_replacement"];

		$link = napcdoc::html_createElement("a", [
			// no fixLink needed
			"href" => "./$replacement.html#$replacement"
		], $replacement);

		$replace_with_text = "Use $link instead of this $type.";
	}

	echo napcdoc::site_renderTemplateFile("component/content-box", [
		"type" => "deprecation",
		"content" => "<p>This $type is deprecated and will be removed in the next major version.</p><p>$replace_with_text</p>"
	]);
}
