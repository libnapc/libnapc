<?php

return function() {
	$nm_output = napphp::arr_join(XPHPUtils::shell_assertExecCall(
		"nm", ["build/lib/libnapc-local.a"]
	), "\n");

	$symbols = napphp::fs_readFileJSON("build/doc/symbols.json");

	foreach ($symbols["functions"] as $fn_name => &$_) {
		$has_hal = !!strlen(strstr($nm_output, "HAL_".$fn_name));

		if ($has_hal && !in_array("hal", $_["flags"])) {
			$_["flags"][] = "hal";
		}
	}

	napphp::fs_writeFileJSONAtomic(
		"build/doc/symbols.tagged.json",
		$symbols
	);
};

