<?php

return function($args, &$context) {
	$output_dir = $context["output_dir"];
	$generator_fn = $context["generator_fn"];

	foreach ($context["napc"]["modules"] as $module_name => $module_definitions) {
		if ($module_name === "app") continue;

		napphp::fs_mkdir("$output_dir/definition/$module_name");

		foreach ($module_definitions as $definition) {
			$definition_name = substr($definition, 2);

			fwrite(STDOUT, "Exporting definition '$definition_name'\n");

			napphp::fs_writeFileStringAtomic(
				"$output_dir/definition/$module_name/$definition_name.html",
				$generator_fn("/definition/$module_name/$definition_name.html")
			);
		}
	}
};


