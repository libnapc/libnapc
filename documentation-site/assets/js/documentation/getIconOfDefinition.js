window.napcdoc.lib.getIconOfDefinition = function(definition_name, width, height) {
	const definition  = window.napcdoc.definitions[definition_name]
	let icon = "type_icon/fn"

	switch (definition.type) {
		case "fn": {
			icon = "type_icon/fn"
		} break;

		case "type": {
			if (definition.kind === "struct") {
				icon = "type_icon/outline/struct"
			} else if (definition.kind === "opaque") {
				icon = "type_icon/filled/struct"
			} else if (definition.kind === "enum") {
				icon = "type_icon/outline/enum"
			} else {
				icon = "type_icon/outline/type"
			}
		} break;

		case "macro":
			icon = "type_icon/filled/macro"
	}

	return window.napcdoc.lib.getSVGMarkup(icon, width, height)
}
