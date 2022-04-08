window.napcdoc.lib.unblurContent = function() {
	if (!("_blur_counter" in window.napcdoc)) {
		console.error("unblurContent called before blurContent() got called")

		return
	}

	let new_blur_counter = window.napcdoc._blur_counter - 1

	if (new_blur_counter === 0) {
		document.querySelector("#nd-right-content").classList.remove("blurred")
	}

	window.napcdoc._blur_counter = new_blur_counter
	console.log("dec", window.napcdoc._blur_counter)
}
