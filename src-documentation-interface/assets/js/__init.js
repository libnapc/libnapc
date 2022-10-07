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

function toggleTheme() {
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

document.querySelector(".theme-switcher").addEventListener("click", function(e) {
	toggleTheme()
})

window.addEventListener("keydown", (e) => {
	// SHIFT + /
	if (e.keyCode === 191 && e.getModifierState("Shift")) {
		toggleTheme()
	}
})

function highlightElement(element) {
	let language = element.getAttribute("data-language")
	if (!language || language === "none" || language === "unknown") {
		console.warn("data-language missing for element, falling back to 'c'", element)

		language = "c"
	}

	element.innerHTML = window.hljs.highlight(element.innerText, {
		language
	}).value

	element.innerHTML = replaceDefinitions(element.innerHTML)
}

document.querySelectorAll("pre.code.hljs").forEach(highlightElement)
document.querySelectorAll("pre.code-inside-content-box.hljs").forEach(highlightElement)

//window.napcdoc.lib.initPopover()
window.napcdoc.lib.initGlobalSearch()
window.napcdoc.lib.initLocalSearch()
