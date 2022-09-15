<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];
	$generator_fn = $context["generator_fn"];

	$URLs = ["site.css", "site.js", "metadata.xml", "index.html", "404.html"];

	foreach ($URLs as $url) {
		fwrite(STDOUT, "Exporting misc '$url'\n");

		napphp::fs_writeFileStringAtomic(
			"$output_dir/$url", $generator_fn("/$url")
		);
	}
};
