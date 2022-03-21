function replaceDefinitions(code) {
	let definition_names = Object.keys(window.napcdoc.definitions)

	definition_names = definition_names.sort((a,b) => b.length - a.length)

	let regex = new RegExp(definition_names.join("|"), "g")

	code = code.replaceAll(
		regex, (m) => {
			let kind = window.napcdoc.definitions[m].type

			if (kind === "fn") kind = "function"

			const module_name = window.napcdoc.lib.getModuleOfDefinition(m)

			const link = window.napcdoc.lib.fixLink(
				`${module_name}/${m}.html#${m}`
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

let has_focus = false

document.querySelector("#napcdoc-content").addEventListener("mouseleave", (e) => {
	document.querySelector("#napcdoc-layout-content").classList.add("dimmed")

	has_focus = false
})

document.querySelector("#napcdoc-content").addEventListener("mouseenter", (e) => {
	document.querySelector("#napcdoc-layout-content").classList.remove("dimmed")

	has_focus = true
})

setTimeout(() => {
	if (!has_focus) {
		document.querySelector("#napcdoc-layout-content").classList.add("dimmed")
	}
}, 2500)

setTimeout(() => {
	document.body.classList.add("animate")
}, 0)

window.napcdoc.lib.initPopover()
window.napcdoc.lib.initGlobalSearch()
window.napcdoc.lib.initLocalSearch()
