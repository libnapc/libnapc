window.napcdoc.lib.replaceBackticks = function(text) {
	let out = ""
	let open = false

	for (let i = 0; i < text.length; ++i) {
		let ch = text[i]

		if (ch === "`") {
			if (!open) {
				out += `<span class="bt-pill text">`
			} else {
				out += `</span>`
			}

			open = !open
		} else {
			out += ch
		}
	}

	return out
}
