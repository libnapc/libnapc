<style>
div.definition-section-title {
	display: flex;
	align-items: center;
	justify-content: center;
}

div.definition-section-title h3 {
	flex-shrink: 0;
	padding-right: 10px;
	font-size: 14px;
	text-transform: uppercase;
	color: #454559;
}

div.definition-section-title hr {
	width: 100%;
	background: rgba(255, 255, 255, .2);
	background: linear-gradient(90deg, #454559 30%, rgba(255,255,255,0) 100%);
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
	"fn/params",
	"fn/return",
	"struct/members",
	"enum/values",
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
