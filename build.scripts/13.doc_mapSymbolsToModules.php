<?php

return function() {
	$symbols = napphp::fs_readFileJSON("build/doc/symbols.json");
	$types_module_map = napphp::fs_readFileJSON("build.scripts/doc/types_module_map.json");

	$functions = $symbols["functions"];
	$types = $symbols["types"];

	$modules = [
		"Core" => []
	];

	foreach ($functions as $function => $_) {
		$tmp = napphp::str_split($function, " ");

		if (2 >= sizeof($tmp)) {
			$modules["Core"][] = "f:".$function;
		} else {
			$module_name = $tmp[1];

			if (!napphp::arr_keyExists($modules, $module_name)) {
				$modules[$module_name] = [];
			}

			$modules[$module_name][] = "f:".$function;
		}
	}

	foreach ($types as $type) {
		$tmp = explode("_", $type);

		if (sizeof($tmp) === 2) {
			$modules["Core"][] = "t:$type";
		} else {
			array_shift($tmp);
			array_shift($tmp);

			$tmp = "napc__".implode("_", $tmp);
			$guessed_mod = NULL;

			if (napphp::arr_keyExists($types_module_map, $tmp)) {
				$guessed_mod = $types_module_map[$tmp];
			}

			if ($guessed_mod) {
				$modules[$guessed_mod][] = "t:$type";
			} else {
				fprintf(STDERR, "Unmapped $tmp\n");
			}
		}
	}

	$macros = napphp::fs_readFileJSON("build.scripts/doc/macros.json")["macros"];

	foreach ($macros as $target_module => $macro_names) {
		foreach ($macro_names as $macro_name) {
			if (!napphp::arr_keyExists($modules, $target_module)) {
				$modules[$target_module] = [];
			}

			$modules[$target_module][] = "m:$macro_name";
		}
	}

	napphp::fs_writeFileJSONAtomic(
		"build/doc/modules_symbols_map.json",
		$modules, true
	);
};
