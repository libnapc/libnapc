<?php

$is_opaque_type = false;
$opaque_type_notes_text = "";

if ($__keys["type"] === "type" && $__keys["kind"] === "opaque") {
	$is_opaque_type = true;
	$opaque_type_notes_text = "Treat this type as opaque.";
}

if (strlen($__keys["general_info"]["notes"] ?? "") || $is_opaque_type) {
	if ($is_opaque_type) {
		$note_text = $opaque_type_notes_text;
	} else {
		$note_text = napcdoc::format_multiLine($__keys["general_info"]["notes"]);
	}

	echo napcdoc::site_renderTemplateFile("component/content-box", [
		"type" => "info",
		"content" => $note_text
	]);
}
