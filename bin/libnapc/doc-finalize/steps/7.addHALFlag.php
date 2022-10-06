<?php

return function($args, &$context) {
	$nm_output_file = napphp::tmp_createFile();

	napphp::shell_execute(
		"nm", [
			"args" => [
				$context["libnapc.a"]
			],
			"stdout" => $nm_output_file
		]
	);

	$nm_output = napphp::fs_readFileString($nm_output_file);

	$output = &$context["output"];

	foreach ($output["definitions"] as $definition_name => &$definition) {
		if ($definition["type"] !== "fn") continue;

		$fn_name = $definition["name"];

		$definition["is_part_of_HAL"] = napphp::str_contains($nm_output, "HAL_$fn_name");
	}
};
