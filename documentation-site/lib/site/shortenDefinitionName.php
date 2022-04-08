<?php

return function($definition_name) {
	// never shorten types
	if (napcdoc::util_startsWith($definition_name, "napc__")) {
		return $definition_name;
	}
	// never shorten macros
	if (napcdoc::util_startsWith($definition_name, "NAPC_")) {
		return $definition_name;
	}

	$parts = explode("_", $definition_name);

	// napc_getVersion etc.
	if (sizeof($parts) === 2) {
		return $definition_name;
	}

	list($napc, $module_name) = $parts;

	return substr($definition_name, strlen("napc_".$module_name."_"));
};
