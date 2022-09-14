window.napcdoc.lib.blurContent = function() {
	if (!("_blur_counter" in window.napcdoc)) {
		window.napcdoc._blur_counter = 0
	}

	let new_blur_counter = window.napcdoc._blur_counter + 1

	if (new_blur_counter === 1) {
		document.querySelector("#nd-right-content").classList.add("blurred")
	}

	window.napcdoc._blur_counter = new_blur_counter
	console.log("inc", window.napcdoc._blur_counter)
}
