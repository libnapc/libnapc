function shortenFunctionName(definition_name, definition_module) {
	if (definition_module === "Core") {
		return definition_name
	}

	return definition_name.slice(`napc_`.length)
}

window.napcdoc.lib.createGlobalSearchSpace = function() {
	let ret = []

	for (const definition_name in window.napcdoc.definitions) {
		const definition_module = window.napcdoc.lib.getModuleOfDefinition(definition_name)
		const definition = window.napcdoc.definitions[definition_name]
		let label = definition_name

		// ignore undocumented definitions
		if (!("general_info" in definition)) continue

		if (definition.type === "fn") {
			label = shortenFunctionName(definition_name, definition_module)
		}

		if (label.length) {
			ret.push({
				definition: definition_name,
				label
			})
		}
	}

	return ret
}
