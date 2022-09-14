window.napcdoc.lib.getProtoOfDefinition = function(definition_name) {
	for (const element of document.querySelectorAll("[data-code-definition]")) {
		const a = element.getAttribute("data-code-definition")

		if (a === definition_name) {
			return element.innerHTML
		}
	}

	return "???"
}
