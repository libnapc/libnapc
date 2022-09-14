<?php

return function($definition_name) {
	$napc = napcdoc::site_getDocumentation();

	$definition = $napc["definitions"][$definition_name];

	switch ($definition["type"]) {
		case "fn":
			return napcdoc::format_proto_fn($definition_name);

		case "type":
			return napcdoc::format_proto_type($definition_name);

		case "macro":
			return napcdoc::format_proto_macro($definition_name);
	}

	throw new Exception("Unknown definition '$definition_name'");
};
