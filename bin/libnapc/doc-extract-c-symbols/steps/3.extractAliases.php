<?php

return function($args, &$context) {
	$aliases = [];

	foreach ($context["typedefs"] as $type_name => $type_info) {
		if ($type_info["typedef_type"] !== "alias") continue;
		// napc__ types *never* aliases
		//if (napphp::str_contains($type_name, "__")) continue;

		$aliases[$type_name] = $type_info["original_name"];

		fwrite(STDOUT, "Found alias '$type_name' -> '".$type_info["original_name"]."'\n");
	}

	$context["aliases"] = $aliases;
};
