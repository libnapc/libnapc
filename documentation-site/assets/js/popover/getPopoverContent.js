function popoverContentSection(definition, section) {
	let ret = ``
	let label = "???"

	switch (section) {
		case "params":
			label = "Parameter"
		break;

		case "fields":
			label = "Members"
		break;

		case "values":
			label = "Values"
		break;
	}

	ret += `<h2>${label}</h2><hr>`
	ret += `<div class="flex-table">`

	for (const value of definition[section]) {
		ret += `<div class="flex-table-row">`
		ret += `	<div class="flex-table-row-cell" style="font-size:14px">`
		ret += `		${value.name}`
		ret += `	</div>`
		ret += `</div>`
		ret += `<div class="flex-table-row">`
		ret += `	<div class="flex-table-row-cell" style="color: #7C7B7C;">`
		ret += `		${window.napcdoc.lib.replaceBackticks(value.description)}`
		ret += `	</div>`
		ret += `</div>`
	}

	ret += `</div>`

	return ret
}

window.napcdoc.lib.getPopoverContent = function(definition_name, definition) {
	let ret = ``

	ret += `
	<div class="popover-content-top">
		${window.napcdoc.lib.getIconOfDefinition(definition_name, 18, 18)}
		<h1>${definition_name}</h1>
	</div>
	`

	if (!("brief" in definition.general_info)) {
		//alert("oops")
		definition.general_info.brief = "NO BRIEF FOUND"
	}

	let style = ""

	if (definition.type === "type" && (definition.kind === "alias" || definition.kind === "opaque")) {
		style = `style="margin-bottom:0px"`
	}

	ret += `<span class="brief" ${style}>${
		window.napcdoc.lib.replaceBackticks(definition.general_info.brief)
	}</span>`

	if (definition.type === "fn") {
		ret += window.napcdoc.lib.getProtoOfDefinition(definition_name)
		ret += popoverContentSection(definition, "params")

		if (!definition.params.length) {
			ret += `<i>This function does not take any parameter.</i>`
		}

		ret += `<div style="height:10px;"></div>`

		ret += `<h2>Returns</h2><hr>`

		if (definition.return.type === "void") {
			ret += `<i>This function does not return anything.</i>`
		} else {
			ret += window.napcdoc.lib.replaceBackticks(definition.return.description)
		}
	} else if (definition.type === "type") {
		if (definition.kind !== "opaque") {
			ret += window.napcdoc.lib.getProtoOfDefinition(definition_name)
		}

		if (definition.kind === "enum" || definition.kind === "struct") {
			ret += popoverContentSection(
				definition, definition.kind === "enum" ? "values" : "fields"
			)
		}
	}

	return ret
}
