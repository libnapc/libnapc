<style>
div.api-reference-module-boxes {
	display: flex;
	flex-wrap:  wrap;
	align-items: flex-start;
}

@media only screen and (max-width: 1000px) {
	div.api-reference-module-box {
		width: 100% !important;
	}
}

div.api-reference-module-box {
	width: 300px;
	flex-grow: 0;
	flex-shrink: 0;
	background: var(--code-background);
	border-radius: 4px;
	padding: 20px 20px;
	margin: 5px;
	height: auto;
}

div.api-reference-module-box h2 {
	font-size: 1.2rem;
	color: var(--text-gradient-color-1);
	margin: 6px 0px;
	margin-top: 0 !important;
	background: -webkit-linear-gradient(274deg, var(--text-gradient-color-1), var(--text-gradient-color-2));
	-webkit-background-clip: text;
	-webkit-text-fill-color: transparent;
}

div.api-reference-module-box ul {
	line-height: 25px;
	margin-left: 15px !important;
}

div.api-reference-module-box li {
	list-style-type: none;
}

div.api-reference-module-box li a {
	text-decoration: none;
	font-size: 16px;
}

h1.a {
	font-size: 1.5rem;
	margin: 7px 0px;
}
</style>
<?php
echo napcdoc::site_renderTemplateFile("component/generic-page-top", [
	"title" => "API Reference"
]);

foreach (napcdoc::site_getDocumentation()["modules"] as $module_name => $definitions) {
	echo napcdoc::html_createElement("h1", [
		"class" => "a"
	], $module_name);

	$categories = ["f" => [], "t" => [], "m" => []];
	$map = ["f" => "Functions", "t" => "Types", "m" => "Macros"];

	foreach ($definitions as $definition) {
		$categories[substr($definition, 0, 1)][] = substr($definition, 2);
	}

	echo '<div class="api-reference-module-boxes">';

	foreach ($categories as $cat => $entries) {
		if (!sizeof($entries)) continue;

		$box_content  = napcdoc::html_createElement("h2", [], $map[$cat]);
		$box_content .= "<ul>";

		foreach ($entries as $definition_name) {
			$label = napcdoc::site_shortenDefinitionName($definition_name);

			$box_content .= napcdoc::html_createElement("li", [], 
				napcdoc::html_createElement("a", [
					"href" => napcdoc::site_link(
						"definition/$module_name/$definition_name.html#$definition_name"
					)
				], $label)
			);
		}

		$box_content .= "</ul>";

		echo napcdoc::html_createElement("div", [
			"class" => "api-reference-module-box"
		], $box_content);
	}

	echo '</div>';
}
?>
