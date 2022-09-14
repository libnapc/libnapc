<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];
	$generator_fn = $context["generator_fn"];

	napphp::fs_mkdir("$output_dir/module");

	foreach ($context["napc"]["modules"] as $module_name => $module_definitions) {
		if ($module_name === "app") continue;

		fwrite(STDOUT, "Exporting module '$module_name'\n");

		napphp::fs_writeFileStringAtomic(
			"$output_dir/module/$module_name.html", $generator_fn("/module/$module_name.html")
		);
	}
};
