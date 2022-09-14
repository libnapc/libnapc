window.napcdoc.lib.highlightString = function(string, string_to_highlight, html_element) {
	if (!string_to_highlight.length) {
		return string
	}

	// from: https://stackoverflow.com/a/43819621/2005038
	let reg = new RegExp(string_to_highlight, 'gi');

	return string.replace(reg, function(str) {return `<${html_element}>${str}</${html_element}>`;});
}
