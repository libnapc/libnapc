let sections_map = null

function updateSections() {
	const sections = document.querySelectorAll("#napcdoc-layout-navigation a.section")

	for (const section of sections) {
		let children = sections_map[section.innerText.toLowerCase()]

		let visible_children = children.filter(child => {
			return child.classList.contains("search-visible")
		})

		if (!visible_children.length) {
			section.classList.add("section-hidden")
		} else {
			section.classList.remove("section-hidden")
		}
	}
}

function assembleSectionsMap() {
	const elements = document.querySelectorAll("#napcdoc-layout-navigation a")
	let map = {}
	let current_section = null, ref = null

	for (const element of elements) {
		if (element.classList.contains("section")) {
			current_section = element.innerText.toLowerCase()

			map[current_section] = []
		} else {
			map[current_section].push(element)
		}
	}

	return map
}

function renderSearchResults(search_term, search_space) {
	const results = window.napcdoc.lib.search(search_space, search_term, "u")

	for (const result of results) {
		const target_element = document.querySelector(`#${result.definition}`)

		target_element.classList.remove("search-hidden")
		target_element.classList.remove("search-visible")

		if (result.show) {
			target_element.classList.add("search-visible")
		} else {
			target_element.classList.add("search-hidden")
		}

		target_element.querySelector(".label").innerHTML = result.html
	}

	updateSections()
}

window.napcdoc.lib.initLocalSearch = function() {
	sections_map = assembleSectionsMap()

	const elements = document.querySelectorAll("#napcdoc-layout-navigation a")
	let search_space = []

	for (const element of elements) {
		if (element.classList.contains("section")) continue

		search_space.push({
			label: element.querySelector(".label").innerText,
			definition: element.getAttribute("id")
		})
	}

	const module_name = window.napcdoc_requested_module_name

	if (module_name) {
		document.querySelector("#napcdoc-local-search-input").placeholder = `Search a definition of ${module_name}`
	} else {
		document.querySelector("#napcdoc-local-search-input").placeholder = "Search a module"
	}

	document.querySelector("#napcdoc-local-search-input").addEventListener("input", (e) => {
		renderSearchResults(e.currentTarget.value, search_space)
	})
}
