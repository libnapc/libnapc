<?php

$__keys["site_title"] = "Overview";

$__keys["content"] = napcdoc::site_renderMarkdownFile("reference_home");

$__keys["left-navigation"] = [];

$modules_intro = napcdoc::site_getDocumentation()["modules_intro"];

foreach (napcdoc::site_getModules() as $module_name) {
	$__keys["left-navigation"][] = [
		"label" => $module_name,
		"icon" => "module_icon/$module_name",
		"href" => napcdoc::site_link("module/$module_name.html"),
		"name" => $module_name,
		"brief" => $modules_intro[$module_name]["@brief"] ?? ""
	];
}

