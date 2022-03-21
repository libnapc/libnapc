<?php

return function($definition_name) {
	$napc = napcdoc::documentation_get();

	$definition = $napc["definitions"][$definition_name];

	switch ($definition["type"]) {
		case "fn":
			return napcdoc::formatting_proto_fn($definition_name);

		case "type":
			return napcdoc::formatting_proto_type($definition_name);

		case "macro":
			return napcdoc::formatting_proto_macro($definition_name);
	}

	throw new Exception("Unknown definition '$definition_name'");
};
