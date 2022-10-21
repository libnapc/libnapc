<?php

$notes = [];

if (sizeof($__keys["general_info"]["notes"] ?? [])) {
	$notes = $__keys["general_info"]["notes"];
}

if ($__keys["type"] === "type" && $__keys["kind"] === "opaque") {
	array_unshift($notes, "Treat this type as opaque.");
}

if (sizeof($notes)) {
	foreach ($notes as $note_text) {
		echo napcdoc::site_renderTemplateFile("component/content-box", [
			"type" => "info",
			"content" => napcdoc::format_multiLine($note_text)
		]);
	}
}
