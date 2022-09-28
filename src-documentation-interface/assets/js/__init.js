function replaceDefinitions(code) {
	let definition_names = Object.keys(window.napcdoc.definitions)

	definition_names = definition_names.sort((a,b) => b.length - a.length).filter(definition_name => {
		return "general_info" in window.napcdoc.definitions[definition_name]
	})

	let regex = new RegExp(definition_names.join("|"), "g")

	code = code.replaceAll(
		regex, (m) => {
			let kind = window.napcdoc.definitions[m].type

			if (kind === "fn") kind = "function"

			const module_name = window.napcdoc.lib.getModuleOfDefinition(m)

			const link = window.napcdoc.lib.fixLink(
				`definition/${module_name}/${m}.html#${m}`
			)

			return `<span class="c-${kind}" style="font-weight:400;"><a style="text-decoration:none" href="${link}">${m}</a></span>`
		}
	)

	return code
}

function setTheme(theme_name) {
	document.body.classList.remove("theme-light")
	document.body.classList.remove("theme-dark")

	if (theme_name === "light") {
		document.body.classList.add("theme-light")
	} else {
		document.body.classList.add("theme-dark")
	}
}

window.addEventListener("keydown", (e) => {
	// SHIFT + /
	if (e.keyCode === 191 && e.getModifierState("Shift")) {
		let theme = ""

		if (document.body.classList.contains("theme-dark")) {
			theme = "light"
		} else {
			theme = "dark"
		}

		console.log("Saved theme '" + theme + "'")

		window.localStorage.setItem("theme", theme)

		setTheme(theme)
	}
})

try {
	let saved_theme = window.localStorage.getItem("theme") || "dark"

	setTheme(saved_theme)
} catch (error) {
	console.error("Could not apply theme because of", error)
}

document.querySelectorAll("pre.code.hljs").forEach(el => {
	el.innerHTML = window.hljs.highlight(el.innerText, {
		language: "c"
	}).value

	el.innerHTML = replaceDefinitions(el.innerHTML)
})

//window.napcdoc.lib.initPopover()
window.napcdoc.lib.initGlobalSearch()
window.napcdoc.lib.initLocalSearch()
