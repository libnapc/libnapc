function getMenuEntryElements() {
	const elements = document.querySelectorAll("a[data-menu-entry]")
	let ret = []

	for (const element of elements) {
		if (!element.classList.contains("hidden")) {
			ret.push(element)
		}
	}

	return ret
}

function getActiveMenuEntry() {
	const menu_entry_elements = getMenuEntryElements()

	for (let i = 0; i < menu_entry_elements.length; ++i) {
		if (menu_entry_elements[i].classList.contains("active")) {
			return i
		}
	}

	console.error("No active menu entry?")
}

function getCurrentSelection() {
	const menu_entry_elements = getMenuEntryElements()
	let current_position = getActiveMenuEntry()

	for (let i = 0; i < menu_entry_elements.length; ++i) {
		const element = menu_entry_elements[i]

		if (element.classList.contains("selected")) {
			current_position = index

			break
		}
	}

	return current_position
}

function updateUI(position) {
	const menu_entry_elements = getMenuEntryElements()

	for (const element of menu_entry_elements) {
		element.classList.remove("selected")
	}

	menu_entry_elements[position].classList.add("selected")

	if (!window.napcdoc.lib.isInViewPort(menu_entry_elements[position])) {
		menu_entry_elements[position].scrollIntoView({
			behavior: "auto",
			block: "start"
		})
	}
}

window.napcdoc.lib.initNavigation = function() {
	let current_position = getCurrentSelection()

	const global_search_input_element = document.querySelector("#napc-doc-search-input")

	window.addEventListener("keydown", (e) => {
		const menu_entry_elements = getMenuEntryElements()

		/* do not process key events from search input */
		if (e.target === global_search_input_element) {
			return
		}

		/* ignore any key that is not enter,escape,keyup or keydown */
		if (0 > [13, 27, 38, 40].indexOf(e.keyCode)) {
			return
		}

		if (e.keyCode !== 27) {
			e.preventDefault()
		}

		let update_ui = true

		/* up */
		if (e.keyCode === 38) {
			if (current_position > 0) {
				--current_position
			}
		}
		/* down */
		else if (e.keyCode === 40) {
			if ((menu_entry_elements.length - 1) > current_position) {
				++current_position
			}
		}
		/* escape */
		else if (e.keyCode === 27) {
			current_position = active_menu_entry
		}
		/* enter */
		else if (e.keyCode === 13) {
			window.location.href = menu_entry_elements[current_position].getAttribute("data-menu-entry")

			update_ui = false
		}

		if (update_ui) updateUI(current_position)
	})
}
