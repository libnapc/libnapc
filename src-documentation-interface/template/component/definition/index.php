<style>
div.definition-section-title {
	display: flex;
	align-items: center;
	justify-content: center;
}

div.definition-section-title h3 {
	flex-shrink: 0;
	padding-right: 10px;
	
	/*font-size: 14px;
	text-transform: uppercase;
	color: var(--section-title-color);
	*/

	font-size: 16px;
	color: var(--base-text-color);
}

div.definition-section-title hr {
	width: 100%;
	background: rgba(255, 255, 255, .2);
	background: linear-gradient(90deg, var(--section-title-color) 30%, transparent 100%);
	background: var(--code-border);
	border: none;
	height: 2px;
	margin: 0 !important;
}
</style>

<div class="module-definition">
<?php

$definition_name = $__keys["definition_name"];
$definition = napcdoc::site_getDocumentation()["definitions"][$definition_name];

$sections = [
	"description",
	"proto",
	"rationale",
	"notes",
	//"fn/params",
	"fn/return",
	//"struct/members",
	//"enum/values",
	"hal",
	"deprecation",
	"warning",
	"example",
	"changelog"
	//"availability"
];

$definition["definition_name"] = $definition_name;

foreach ($sections as $section) {
	echo napcdoc::site_renderTemplateFile(
		"component/definition/$section", $definition
	);
}
?>
</div>
