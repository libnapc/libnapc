<?php

return function() {
	$symbols = json_decode(file_get_contents("build/doc/symbols.json"), true);

	$functions = $symbols["functions"];
	$types = $symbols["types"];

	$modules = [
		"Core" => []
	];

	foreach ($functions as $function => $_) {
		$tmp = explode("_", $function);

		if (2 >= sizeof($tmp)) {
			$modules["Core"][] = "f:".$function;
		} else {
			$module_name = $tmp[1];

			if (!array_key_exists($module_name, $modules)) {
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

			$tmp = implode("_", $tmp);
			$guessed_mod = NULL;

			foreach ($modules as $m => $_) {
				if (strstr($tmp, $m)) {
					$guessed_mod = $m;
					break;
				}
			}

			if ($guessed_mod) {
				$modules[$guessed_mod][] = "t:$type";
			} else {
				fprintf(STDERR, "Oops! $tmp\n");
			}
		}
	}

	$macros = json_decode(file_get_contents("build.scripts/doc/macros.json"), true)["macros"];

	foreach ($macros as $target_module => $macro_names) {
		foreach ($macro_names as $macro_name) {
			if (!array_key_exists($target_module, $modules)) {
				$modules[$target_module] = [];
			}

			$modules[$target_module][] = "m:$macro_name";
		}
	}

	file_put_contents(
		"build/doc/modules_symbols_map.json",
		json_encode($modules, JSON_PRETTY_PRINT)
	);
};
