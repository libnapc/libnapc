<?php

return function($definition) {
	if ($definition["type"] === "fn") {
		echo '<div class="module-section">';
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Function Protoype"
		]);

		echo napcdoc::formatting_proto_fn($definition["name"]);
		echo '</div>';
	} else if ($definition["type"] === "macro" && array_key_exists("params", $definition)) {
		echo '<div class="module-section">';
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Macro Definition"
		]);

		echo napcdoc::formatting_proto_macro($definition["name"]);
		echo '</div>';
	} else if ($definition["type"] === "type" && $definition["kind"] !== "opaque") {
		echo '<div class="module-section">';
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Type Definition"
		]);

		echo napcdoc::formatting_proto_type($definition["name"]);
		echo '</div>';
	}
};
