<?php

return function($definition_name) {
	$definition = napcdoc::documentation_getDefinition($definition_name);

	switch ($definition["type"]) {
		case "fn":
			return "type_icon/fn";

		case "macro":
			return "type_icon/filled/macro";

		case "type": {
			if ($definition["kind"] === "struct") {
				return "type_icon/outline/struct";
			} else if ($definition["kind"] === "opaque") {
				return "type_icon/filled/struct";
			} else if ($definition["kind"] === "enum") {
				return "type_icon/outline/enum";
			}

			return "type_icon/filled/type";
		}
	}

	return "book-open";
};
