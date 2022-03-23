<?php

return function() {
	$arch = XPHPUtils::shell_assertExecCall("uname -m")[0];

	$nm_output = implode("\n", XPHPUtils::shell_assertExecCall(
		"nm", ["build/lib/libnapc-$arch.a"]
	));

	$symbols = json_decode(file_get_contents("build/doc/symbols.json"), true);

	foreach ($symbols["functions"] as $fn_name => &$_) {
		$has_hal = !!strlen(strstr($nm_output, "HAL_".$fn_name));

		if ($has_hal && !in_array("hal", $_["flags"])) {
			$_["flags"][] = "hal";
		}
	}

	file_put_contents(
		"build/doc/symbols.tagged.json",
		json_encode($symbols, JSON_PRETTY_PRINT)
	);
};

