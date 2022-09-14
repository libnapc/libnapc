window.napcdoc.lib.getSVGMarkup = function(svg, width, height) {
	let svg_content = window.napcdoc.assets.svg[`${svg}.svg`]

	svg_content = svg_content.replace(/width="([0-9]+)"/, `width="${width}"`)
	svg_content = svg_content.replace(/height="([0-9]+)"/, `height="${height}"`)

	return `
	<div
		class="napcdoc-svg-image"
		style="width:${width}px;height:${height}px;display:flex;align-items:center;justify-content:center;flex-grow:0;flex-shrink:0">
		${svg_content}
	</div>
	`
}

