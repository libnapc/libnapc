document.querySelector("#napcdoc-layout-mobile-navigation").addEventListener("transitionend", (e) => {
	const style = window.getComputedStyle(e.currentTarget)

	if (0.01 > style.opacity) {
		e.currentTarget.style.display = "none"
	}
})

document.querySelector("#napcdoc-layout-mobile-navigation-toggle").addEventListener("click", (e) => {
	var is_visible = window.getComputedStyle(
		document.querySelector(".open-menu")
	).display !== "none"
	var wants_open = !document.body.classList.contains("mobile-navigation-open")

	if (wants_open && !is_visible) return

	if (!document.body.classList.contains("mobile-navigation-open")) {
		document.querySelector("#napcdoc-layout-mobile-navigation").style.display = "flex"

		setTimeout(() => {
			document.querySelector("#napcdoc-layout-mobile-navigation").style.opacity = 1
		}, 0)
	} else {
		document.querySelector("#napcdoc-layout-mobile-navigation").style.opacity = 0
	}

	document.body.classList.toggle("mobile-navigation-open")
})

window.addEventListener("resize", (e) => {
	// force close mobile navigation as it interferes with desktop UI
	if (window.outerWidth > 1000) {
		document.body.classList.remove("mobile-navigation-open")
		document.querySelector("#napcdoc-layout-mobile-navigation").style.opacity = 0
	}
	// force close global search as it interferes with mobile UI
	else {
		window.napcdoc.lib.hideGlobalSearchResults()
	}
})
