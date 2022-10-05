<?php

if ($__keys["type"] === "fn") {

	echo napcdoc::site_renderTemplateFile("component/content-box", [
		"type" => "declaration",
		"content" => napcdoc::format_proto_fn($__keys["definition_name"])
	]);

} else if ($__keys["type"] === "macro" && array_key_exists("params", $__keys)) {

	echo napcdoc::site_renderTemplateFile("component/content-box", [
		"type" => "declaration",
		"content" => napcdoc::format_proto_macro($__keys["definition_name"])
	]);

} else if ($__keys["type"] === "type" && $__keys["kind"] !== "opaque") {

	echo napcdoc::site_renderTemplateFile("component/content-box", [
		"type" => "declaration",
		"content" => napcdoc::format_proto_type($__keys["definition_name"])
	]);

}
