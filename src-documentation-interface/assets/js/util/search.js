/**
 *
 */
window.napcdoc.lib.search = function(search_space, search_term, highlight_element) {
	let results = search_space.map(entry => {
		const search_terms = search_term.split(" ")
		let include = true

		/**
		 * multiple search terms are treated as AND
		 * example: "parse dns" -> MUST include "parse" AND "dns"
		 */
		for (const term of search_terms) {
			if (!entry.label.toLowerCase().includes(term.toLowerCase())) {
				include = false

				break
			}
		}

		return {
			...entry,
			show: include
		}
	})

	if (!search_term.length) {
	//	return []
	}

	return results.map(result => {
		let html = result.label

		for (const term of search_term.split(" ")) {
			html = window.napcdoc.lib.highlightString(html, term, highlight_element)
		}

		return {
			...result,
			html,
			module: window.napcdoc.lib.getModuleOfDefinition(result.definition)
		}
	})
}
