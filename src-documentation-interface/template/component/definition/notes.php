<?php

$is_opaque_type = false;
$opaque_type_notes_text = "";

if ($__keys["type"] === "type" && $__keys["kind"] === "opaque") {
	$is_opaque_type = true;
	$opaque_type_notes_text = "Treat this type as opaque.";
}

if (strlen($__keys["general_info"]["notes"] ?? "") || $is_opaque_type) {
	echo '<div class="module-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Notes"
	]);

	if ($is_opaque_type) {
		echo $opaque_type_notes_text;
	} else {
		echo napcdoc::format_multiLine($__keys["general_info"]["notes"]);
	}

	echo '</div>';
}
