<?php

$has_left_navigation = sizeof($__keys["left-navigation"] ?? []) > 0;

echo napcdoc::site_renderTemplateFile(
	"component/header", [
		"has_left_navigation" => $has_left_navigation
	]
);
?>

<div id="nd-global-search-results">
	<div class="wrapper"></div>
</div>

<?php
	if ($has_left_navigation) {
		echo napcdoc::site_renderTemplateFile(
			"component/left-navigation", [
				"entries" => $__keys["left-navigation"]
			]
		);
	}
?>

<?php
	echo napcdoc::site_renderTemplateFile(
		"component/right-content", [
			"has_left_navigation" => $has_left_navigation,
			"content" => $__keys["content"],
			"mobile_navigation_menu" => $__keys["left-navigation"] ?? []
		]
	);
?>

<?php
	echo napcdoc::site_renderTemplateFile(
		"component/footer"
	);
?>
