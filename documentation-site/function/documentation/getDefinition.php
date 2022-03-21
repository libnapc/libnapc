<?php

return function($definition_name) {
	$napc = napcdoc::documentation_get();

	$tmp = json_decode(json_encode($napc["definitions"][$definition_name]), true);

	$tmp["name"] = $definition_name;

	return $tmp;
};
