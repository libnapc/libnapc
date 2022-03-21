<?php

return function($definition) {
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
		"changelog",
		"availability"
	];

	foreach ($sections as $section) {
		echo napcdoc::renderFile(
			"module/$section", $definition
		);
	}
};
