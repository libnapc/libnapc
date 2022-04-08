<?php

if ($__keys["type"] === "fn") {
	echo '<div class="definition-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Function Protoype"
	]);

	echo napcdoc::format_proto_fn($__keys["definition_name"]);
	echo '</div>';
} else if ($__keys["type"] === "macro" && array_key_exists("params", $__keys)) {
	echo '<div class="definition-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Macro Definition"
	]);

	echo napcdoc::format_proto_macro($__keys["definition_name"]);
	echo '</div>';
} else if ($__keys["type"] === "type" && $__keys["kind"] !== "opaque") {
	echo '<div class="definition-section">';
	echo napcdoc::site_renderTemplateFile("component/definition/section-title", [
		"label" => "Type Definition"
	]);

	echo napcdoc::format_proto_type($__keys["definition_name"]);
	echo '</div>';
}
