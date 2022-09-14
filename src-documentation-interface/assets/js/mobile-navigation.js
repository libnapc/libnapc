const mobile_nav = document.querySelector("#nd-mobile-navigation")
const style = document.createElement("style")

style.type = "text/css"

function measureAndSetup() {
	let saved_display = mobile_nav.style.display

	mobile_nav.style.maxHeight = "none"
	mobile_nav.style.display = "block"

	const height = mobile_nav.getBoundingClientRect().height

	mobile_nav.style.transition = "all .1s linear"
	mobile_nav.style.maxHeight = "0px"
	mobile_nav.style.display = saved_display

	return height
}

style.innerHTML = `
body.mobile-navigation-open #nd-mobile-navigation {
	max-height: ${measureAndSetup()}px !important;
}
`
document.getElementsByTagName("head")[0].appendChild(style)

document.querySelector("#toggle-mobile-menu").addEventListener("click", (e) => {
	if (e.currentTarget.classList.contains("empty")) {
		return
	}

	if (document.body.classList.contains("mobile-navigation-open")) {
		document.body.classList.remove("mobile-navigation-open")
	} else {
		document.body.classList.add("mobile-navigation-open")

		mobile_nav.style.maxHeight = "none"

		const height = mobile_nav.getBoundingClientRect().height

		mobile_nav.style.transition = "all .1s linear"
		mobile_nav.style.maxHeight = "0px"

		setTimeout(() => {
			mobile_nav.style.maxHeight = `${height}px`
		})
	}

})
