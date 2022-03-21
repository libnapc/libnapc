<?php

require_once __DIR__."/../lib/napc_doc.php";

function favicon_module($module_name, $selected_definition) {
	if (!$selected_definition) {
		return "module_icon/$module_name.png";
	}

	$definition = napc_doc()["definitions"][$selected_definition];

	switch ($definition["type"]) {
		case "fn":
			return "icon/fn_white.png";

		case "type":
			if ($definition["kind"] === "struct") {
				return "icon/struct_outline.png";
			} else if ($definition["kind"] === "opaque") {
				return "icon/struct.png";
			} else {
				return "icon/type.png";
			}
		break;

		case "macro":
			return "icon/macro.png";
	}
}
