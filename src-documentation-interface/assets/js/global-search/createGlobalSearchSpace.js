window.napcdoc.lib.createGlobalSearchSpace = function() {
	let ret = []

	// search space is order sensitive
	const modules = Object.keys(window.napcdoc.modules).filter(module_name => {
		return module_name !== "app"
	})

	for (const module_name of modules) {
		// add module definitions after module
		const definitions = window.napcdoc.modules[module_name]

		for (const definition of definitions) {
			let definition_name = definition.slice(2)
			let label = definition_name
			const definition_meta = window.napcdoc.definitions[definition_name]

			// ignore undocumented definitions
			if (!definition_meta || !("general_info" in definition_meta)) {
				console.log("skip", definition_name)

				continue
			}

			// always shorten non-core function names
			if (definition.slice(0, 2) === "f:" && module_name !== "Core") {
				label = definition_name.slice(`napc_`.length)
			}

			ret.push({
				definition: definition_name,
				module_name,
				label
			})
		}
	}

	return ret
}
