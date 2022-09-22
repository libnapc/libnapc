<?php

return function($args, &$context) {
	$macros = [];
	$macro_definitions = napphp::fs_readFileJSON(__DIR__."/macro_definitions.json");

	foreach ($macro_definitions["macros"] as $macro_name) {
		$macros[$macro_name] = [];
	}

	$context["macros"] = $macros;
};
