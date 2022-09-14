<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];
	$generator_fn = $context["generator_fn"];

	$pages = ["api", "debug", "releases", "home"];

	foreach ($pages as $page_name) {
		fwrite(STDOUT, "Exporting page '$page_name'\n");

		napphp::fs_writeFileStringAtomic(
			"$output_dir/$page_name.html", $generator_fn("/$page_name.html")
		);
	}
};
