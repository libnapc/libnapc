const POPOVER_WIDTH = 400

function getContentScrollPosition() {
	return document.querySelector("#napcdoc-layout-content").scrollTop
}

function setContentHeight({min_height, content_height}) {
	const height = min_height - content_height

	document.querySelector("#popover_padding_div").style.height = `${height}px`
}

function restoreContentHeight() {
	document.querySelector("#popover_padding_div").style.height = `0px`
}

/**
 * Get the content's height (independent of window size)
 */
function getContentHeight() {
	return document.querySelector("#napcdoc-layout-content").scrollHeight
}

/**
 * Holds the reference element (element that received mouseenter)
 * and the cloned element that was created on mouseenter
 */
let current_context = {
	reference_element: null,
	cloned_element: null,
	popover_element: null
}

/**
 * Function to adjust the content's height to prevent
 * popover content from being cut-off the container.
 */
function adjustContentHeight() {
	const ref = current_context.reference_element
	const popover = current_context.popover_element

	// number of pixels scrolled of #napcdoc-layout-content div 
	let scroll_top = getContentScrollPosition(0)
	// relative position of reference_element 
	let rel_top = ref.getBoundingClientRect().top
	// absolute 
	let abs_top = rel_top + scroll_top

	// height is starting of reference_element + height of popover 
	// .height not reliable because of scale() animation!
	// 100px must be added because of content-header!
	let content_top_padding = 100
	let virtual_height = abs_top + (popover.getBoundingClientRect().height * 1.02) + content_top_padding
	let min_height = virtual_height + 35 + 50 // plus padding 

	let content_height = getContentHeight()

	console.log(Date.now(), "Content's height is " + content_height + "px")
	console.log(Date.now(), "Minimal height required is " + min_height + "px")

	if (min_height > content_height) {
		console.warn(Date.now(), "Content's height is not enough for popover")
		console.log(Date.now(), min_height)

		setContentHeight({
			min_height, content_height
		})
	} else {
		restoreContentHeight()
	}
}

function getCurrentContextDefinition() {
	if (current_context.reference_element) {
		return current_context.reference_element.getAttribute("data-popover")
	}

	return "UNKNOWN"
}

/**
 * Timer to close popover
 */
let close_timer = null

function cancelClose() {
	if (close_timer !== null) {
		console.log(Date.now(), "Stopping close timer", getCurrentContextDefinition())
	}

	clearTimeout(close_timer)
	close_timer = null
}

function requestClose(timeout) {
	clearTimeout(close_timer)

	if (timeout === undefined) {
		timeout = 250
	}

	if (close_timer === null) {
		console.log(Date.now(), "Starting close timer", getCurrentContextDefinition(), timeout)
	} else {
		console.log(Date.now(), "RESTARTING close timer", getCurrentContextDefinition(), timeout)
	}

	close_timer = setTimeout(() => {
		/**
		 * reset close_timer because resetCurrentContext()
		 * closes the popover
		 */
		close_timer = null

		if (current_context.reference_element) {
			resetCurrentContext()
		}
	}, timeout)
}

/**
 * Close popup when mobile view is active
 */
window.addEventListener("resize", (e) => {
	if (1000 > window.innerWidth) {
		requestClose(0)
	}
})

/**
 * Resets the current context:
 * - removes the cloned node from the document
 * - restores the style of the reference element
 */
function resetCurrentContext() {
	if (!current_context.reference_element) {
		console.warn("resetCurrentContext(): nothing to reset")
		return
	}

	/**
	 * Clear cancel timer
	 */
	if (close_timer !== null) {
		console.log(Date.now(), "Cancelling ongoing close timer")

		clearTimeout(close_timer)
		close_timer = null
	}

	const clone = current_context.cloned_element
	const ref = current_context.reference_element

	clone.parentNode.removeChild(clone)
	ref.style.opacity = 1

	current_context.cloned_element = null
	current_context.reference_element = null

	const popover = current_context.popover_element

	popover.parentNode.removeChild(popover)

	restoreContentHeight()
	window.napcdoc.lib.unblurContent()
}

function onWheelEventHandler(e) {
	const content = document.querySelector("#napcdoc-layout-content")

	content.scrollTop += e.deltaY
}

function initContext(reference_element) {
	if (current_context.reference_element) {
		console.error("initContext() current context was not reset")
		return
	}

	const reference_style = window.getComputedStyle(reference_element)
	// Clone element
	const clone = reference_element.cloneNode(true)

	clone.addEventListener("mouseenter", (e) => {
		cancelClose()
	})

	clone.addEventListener("mouseleave", (e) => {
		requestClose()
	})

	clone.addEventListener("wheel", onWheelEventHandler, {
		passive: true
	})

	// Apply styles
	clone.style.fontFamily = reference_style.fontFamily
	clone.style.fontSize = reference_style.fontSize
	clone.style.fontWeight = reference_style.fontWeight
	clone.style.color = reference_style.color

	clone.style.position = "fixed"
	clone.style.zIndex = 4
	clone.style.top = "0px"
	clone.style.left = "0px"
	clone.style.willChange = "transform"

	const popover = document.createElement("div")

	const definition_name = reference_element.getAttribute("data-popover")
	const definition = window.napcdoc.lib.getDefinition(definition_name)

	popover.className = "popover"
	popover.style.display = "flex"
	popover.style.top = "0px"
	popover.style.left = "0px"
	popover.innerHTML = `
	<div class="popover-content" data-definition-type="${definition.type}">
		<div class="arrow-background"></div>
		<div class="arrow-line"></div>
		${window.napcdoc.lib.getPopoverContent(definition_name, definition)}
	</div>
	`

	popover.addEventListener("wheel", onWheelEventHandler, {
		passive: true
	})

	popover.addEventListener("mouseenter", (e) => {
		cancelClose()
	})

	popover.addEventListener("mouseleave", (e) => {
		requestClose()
	})

	document.body.appendChild(clone)
	document.body.appendChild(popover)

	reference_element.style.opacity = 0

	current_context.reference_element = reference_element
	current_context.cloned_element = clone
	current_context.popover_element = popover

	adjustContentHeight()

	popover.classList.add("visible")

	window.napcdoc.lib.blurContent()
}

function context_updatePositions() {
	if (!current_context.reference_element) {
		console.error("context_updatePositions(): invalid context")
		return
	}

	const clone = current_context.cloned_element
	const ref = current_context.reference_element
	const popover = current_context.popover_element
	const ref_pos = ref.getBoundingClientRect()

	clone.style.transform = `translate3d(${ref_pos.left}px, ${ref_pos.top}px, 0)`

	let left_position = ref_pos.left
	left_position += (ref_pos.width / 2)

	popover.style.top = `${ref_pos.top + 35}px`
	popover.style.left = `${left_position - (POPOVER_WIDTH / 2)}px`
}

function onContentScrolled() {
	if (current_context.reference_element) {
		context_updatePositions()
	}
}

window.napcdoc.lib.initPopover = function() {
	for (const element of document.querySelectorAll("[data-popover]")) {
		const definition_name = element.getAttribute("data-popover")

		element.addEventListener("mouseenter", (e) => {
			if (1000 > window.innerWidth) {
				console.warn("Popover is disabled on mobile", window.innerWidth)

				return
			}

			if (current_context.reference_element) {
				resetCurrentContext()
			}

			initContext(e.currentTarget)
			context_updatePositions()
		})
	}

	document.querySelector("#napcdoc-layout-content").addEventListener("scroll", (e) => {
		onContentScrolled()
	}, {
		passive: true
	})
}
