/**
 * Returns the module that definition_name is a part of
 */
window.napcdoc.lib.getModuleOfDefinition = function(definition_name) {
	for (const module_name in window.napcdoc.modules) {
		for (const module_definition of window.napcdoc.modules[module_name]) {
			let a = module_definition.slice(2)

			if (a === definition_name) {
				return module_name
			}
		}
	}
}
