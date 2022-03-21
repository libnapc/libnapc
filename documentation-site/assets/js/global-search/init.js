const input_element = document.querySelector("#napcdoc-global-search-input")
const results_div = document.querySelector("#napcdoc-layout-global-search-results")

function renderSearchResults(search_term, search_space) {
	const results = window.napcdoc.lib.search(search_space, search_term, "b")

	results_div.innerHTML = ""

	let last_section_type = null

	for (const result of results) {
		if (!result.show) continue

		const a_element = document.createElement("a")

		const definition = window.napcdoc.definitions[result.definition]

		a_element.setAttribute("data-definition-type", definition.type)

		if ("deprecated" in definition.general_info && definition.general_info.deprecated) {
			a_element.classList.add("deprecated")
		}

		a_element.href = window.napcdoc.lib.fixLink(
			`${result.module}/${result.definition}.html#${result.definition}`
		)

		let brief = ""

		if (definition.general_info.brief) {
			brief = `<span class="brief">${definition.general_info.brief}</span>`
		}

		let markup = `
			${window.napcdoc.lib.getIconOfDefinition(result.definition, 18, 18)}

			<div class="label-and-brief">
				<span class="label">${result.html}</span>
				${brief}
			</div>

			${window.napcdoc.lib.getIconOfModule(
				window.napcdoc.lib.getModuleOfDefinition(result.definition)
			, 12, 12)}
		`

		a_element.innerHTML = markup

		const current_section_type = window.napcdoc.definitions[result.definition].type

		if (last_section_type !== current_section_type) {
			const section_delim = document.createElement("h2")

			switch (current_section_type) {
				case "fn":
					section_delim.innerText = "Functions";
				break;
				case "type":
					section_delim.innerText = "Types";
				break;
				case "macro":
					section_delim.innerText = "Macros";
				break;
			}

			results_div.appendChild(section_delim)
			results_div.appendChild(document.createElement("hr"))

			last_section_type = current_section_type
		}

		results_div.appendChild(a_element)
	}
}

function getCurrentSelection() {
	const rendered_results = results_div.querySelectorAll("a")
	let current_position = -1
	let current = null

	for (let i = 0; i < rendered_results.length; ++i) {
		const elm = rendered_results[i]

		if (elm.classList.contains("selected")) {
			current_position = i;
			current = rendered_results[i]
			break;
		}
	}

	let first = rendered_results.length ? rendered_results[0] : null
	let prev = null
	let next = null

	if (current_position !== -1 && rendered_results.length) {
		if (current_position > 0) {
			prev = rendered_results[current_position - 1]
		}

		if ((rendered_results.length - 1) > current_position) {
			next = rendered_results[current_position + 1]
		}
	}

	return {
		first,
		next, current, prev
	}
}

function searchResultsVisible() {
	return results_div.classList.contains("visible")
}

function showSearchResults() {
	if (searchResultsVisible()) return

	results_div.style.display = "flex"
	results_div.classList.add("visible")
	window.napcdoc.lib.blurContent()
}

function hideSearchResults() {
	if (!searchResultsVisible()) return

	results_div.classList.remove("visible")
	window.napcdoc.lib.unblurContent()
}

window.napcdoc.lib.hideGlobalSearchResults = hideSearchResults

window.napcdoc.lib.initGlobalSearch = function() {
	let search_space = window.napcdoc.lib.createGlobalSearchSpace()
	const module_name = window.napcdoc_requested_module_name

	input_element.placeholder = "Search a definition"
	input_element.addEventListener("input", (e) => {
		window.napcdoc.lib.localStorageSet("global_search_term", e.currentTarget.value)

		renderSearchResults(e.currentTarget.value, search_space)
	})

	input_element.addEventListener("focus", (e) => {
		showSearchResults()
	})

	input_element.addEventListener("keydown", (e) => {
		if (e.keyCode === 27) {
			hideSearchResults()
			input_element.blur()

			return
		}

		let selection = getCurrentSelection()

		if (!selection.first) return

		if (!selection.next && !selection.prev) {
			selection.first.classList.add("selected")
			return
		}

		if (!selection.current) return

		let target = null

		// arrow down
		if (e.keyCode === 40 && selection.next) {
			target = selection.next
		}
		// arrow up
		else if (e.keyCode === 38 && selection.prev) {
			target = selection.prev
		}

		if (!target) return

		target.classList.add("selected")
		selection.current.classList.remove("selected")

		let elementTop = results_div.offsetTop;
		let divTop = target.offsetTop;
		let elementRelativeTop = divTop - elementTop;

		if (target === selection.first) {
			results_div.scrollTop = 0
		} else {
			results_div.scrollTop = elementRelativeTop
		}

		/**
		 * Prevent the global keydown event
		 */
		e.stopPropagation()
	})

	input_element.addEventListener("keypress", (e) => {
		if (e.keyCode !== 13) return

		const selection = getCurrentSelection()

		if (selection.current) {
			window.location.href = selection.current.href
		}
	})

	/** init results **/
	{
		const initial_search_term = window.napcdoc.lib.localStorageGet("global_search_term", "")

		renderSearchResults(
			initial_search_term,
			search_space
		)

		input_element.value = initial_search_term
	}

	results_div.addEventListener("transitionend", (e) => {
		const style = window.getComputedStyle(e.currentTarget)

		if (0.01 > style.opacity) {
			e.currentTarget.style.display = "none"
		}
	})

	document.body.addEventListener("click", e => {
		let current_node = e.target
		let hide = true

		while (current_node) {
			if (
				current_node === input_element ||
				current_node === results_div) {
				hide = false
				break;
			}

			current_node = current_node.parentNode
		}

		if (hide) {
			hideSearchResults()
		}
	})
}
