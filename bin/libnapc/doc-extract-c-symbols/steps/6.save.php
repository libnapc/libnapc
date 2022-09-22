<?php

return function($args, &$context) {
	$symbols = [];

	$kind_to_name = function($kind) {
		if ($kind === "structs") return "struct";
		if ($kind === "enums") return "enum";
		if ($kind === "aliases") return "alias";
		if ($kind === "functions") return "function";
		if ($kind === "macros") return "macro";

		return "unknown";
	};

	foreach ([
		"structs", "enums", "aliases", "functions", "macros"
	] as $kind) {
		$symbols_list = $context[$kind];

		foreach ($symbols_list as $sym => $info) {
			array_push(
				$symbols, [
					"name" => $sym,
					"kind" => $kind_to_name($kind),
					"info" => $info
				]
			);
		}
	}

	napphp::fs_writeFileJSONAtomic(
		$context["output-file"], $symbols, true
	);
};
