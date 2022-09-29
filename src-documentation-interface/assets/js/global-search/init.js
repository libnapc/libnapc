const input_element = document.querySelector("#nd-global-search-input")
const results_div = document.querySelector("#nd-global-search-results").querySelector("div.wrapper")

function createEntry(label, brief, icon) {
	const a_element = document.createElement("a")
	let brief_markup = ""

	if (brief.length) {
		brief_markup = `<span class="brief">${brief}</span>`
	}

	a_element.innerHTML = `
	${icon}
	<div class="label-and-brief">
		<span class="label">${label}</span>
		${brief_markup}
	</div>
	`

	return a_element
}

function createModuleHeader(module_name) {
	const module_header = document.createElement("a")
	module_header.classList.add("module-header")

	const module_icon = window.napcdoc.lib.getIconOfModule(
		module_name, 18, 18
	)

	let brief = ""

	if (module_name in window.napcdoc.modules_intro) {
		let module_meta = window.napcdoc.modules_intro[module_name]

		if ("@brief" in module_meta) {
			//brief = `<span class="brief">${module_meta["@brief"]}</span>`
		}
	}

	module_header.innerHTML = `
	${module_icon}

	<div class="label-and-brief">
		<span class="label">${module_name}</span>
		${brief}
	</div>
	`

	module_header.href = window.napcdoc.lib.fixLink(
		`module/${module_name}.html#${module_name}`
	)

	return module_header
}

function renderSearchResults(search_term, search_space) {
	const results = window.napcdoc.lib.search(search_space, search_term, "b")
	results_div.innerHTML = ""

	let last_module_name = ""

	for (const result of results) {
		if (!result.show) continue

		const definition_meta = window.napcdoc.definitions[result.definition]
		let brief = ""

		if ("brief" in definition_meta.general_info) {
			brief = definition_meta.general_info.brief
		}

		let icon = window.napcdoc.lib.getIconOfDefinition(result.definition, 18, 18)

		const a_element = createEntry(
			result.html, brief, icon
		)

		// show module name at the beginning
		if (last_module_name !== result.module_name) {
			results_div.appendChild(
				createModuleHeader(result.module_name)
			)

			last_module_name = result.module_name
		}

		a_element.setAttribute("data-definition-type", definition_meta.type)

		a_element.href = window.napcdoc.lib.fixLink(
			`definition/${result.module_name}/${result.definition}.html#${result.definition}`
		)

		results_div.appendChild(a_element)
	}
}

function getCurrentSelection() {
	const rendered_results = [...results_div.querySelectorAll("a")].filter(element => {
		return !element.classList.contains("module-header")
	})

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

function showSearchResults() {
	if (results_div.parentNode.style.display === "flex") {
		return
	}

	results_div.parentNode.style.display = "flex"
	results_div.parentNode.classList.add("visible")
	window.napcdoc.lib.blurContent()
}

function hideSearchResults() {
	if (results_div.parentNode.style.display !== "flex") {
		return
	}

	results_div.parentNode.style.display = "none"
	results_div.parentNode.classList.remove("visible")
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

	document.body.addEventListener("click", e => {
		let current_node = e.target
		let hide = true

		while (current_node) {
			if (
				current_node === input_element ||
				current_node === results_div.parentNode) {
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
