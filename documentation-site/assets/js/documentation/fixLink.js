/**
 * Fixes links for local use.
 */
window.napcdoc.lib.fixLink = function(link) {
	let pieces = window.napcdoc_request_uri.split("/").filter(piece => {
		return piece.length > 0
	})

	if (pieces.length === 2) {
		return `../${link}`
	}

	return `./${link}`
}
