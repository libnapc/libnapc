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

document.querySelectorAll("pre.code.hljs").forEach(el => {
	el.innerHTML = window.hljs.highlight(el.innerText, {
		language: "c"
	}).value

	el.innerHTML = replaceDefinitions(el.innerHTML)
})

//window.napcdoc.lib.initPopover()
window.napcdoc.lib.initGlobalSearch()
window.napcdoc.lib.initLocalSearch()
