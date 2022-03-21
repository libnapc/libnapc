<?php

chdir(__DIR__."/..");

$arch = trim(exec("uname -m"));

exec("nm ".escapeshellarg("dist/libnapc-$arch.a"), $nm_output, $exit_code);

if ($exit_code !== 0) {
	fwrite(STDERR, "nm returned non-zero exit code\n");
	exit(1);
}

$nm_output = implode("\n", $nm_output);

$symbols = json_decode(file_get_contents("dist/doc/symbols.json"), true);

foreach ($symbols["functions"] as $fn_name => &$_) {
	$has_hal = !!strlen(strstr($nm_output, "HAL_".$fn_name));

	if ($has_hal && !in_array("hal", $_["flags"])) {
		$_["flags"][] = "hal";
	}
}

file_put_contents(
	"dist/doc/symbols.tagged.json",
	json_encode($symbols, JSON_PRETTY_PRINT)
);

