function renderSearchResults(search_term, search_space) {
	const results = window.napcdoc.lib.search(search_space, search_term, "u")

	for (const result of results) {
		const target_element = document.querySelector(`a[name="${result.definition}"]`)

		console.log(result, result.definition, target_element)

		target_element.classList.remove("search-hidden")
		target_element.classList.remove("search-visible")

		if (result.show) {
			target_element.classList.add("search-visible")
		} else {
			target_element.classList.add("search-hidden")
		}

		target_element.querySelector(".label").innerHTML = result.html
	}
}

window.napcdoc.lib.initLocalSearch = function() {
	if (!document.querySelector("#nd-left-navigation")) {
		return
	}

	const elements = document.querySelectorAll("#nd-left-navigation a")
	let search_space = []

	for (const element of elements) {
		search_space.push({
			label: element.querySelector(".label").innerText,
			definition: element.getAttribute("name")
		})
	}

	let placeholder_text = "ERROR"

	if ("napcdoc_requested_module_name" in window) {
		const module_name = window.napcdoc_requested_module_name

		placeholder_text = `Search a definition of ${module_name}`
	} else if (window.napcdoc_request_uri.startsWith("document/") || window.napcdoc_request_uri.startsWith("documentation/")) {
		placeholder_text = `Search a document`
	} else {
		placeholder_text = "Search a module"
	}

	document.querySelector("#nd-local-search-input").placeholder = placeholder_text

	document.querySelector("#nd-local-search-input").addEventListener("input", (e) => {
		renderSearchResults(e.currentTarget.value, search_space)
	})
}
