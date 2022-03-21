<?php

return function($modules) {
	$module_order = [
		"General" => [
			"Core",
			"env",
			"Timer",
			"parser",
			"misc"
		],
		"Memory" => [
			"mem",
			"Buffer",
			"Pool",
			"Writer",
			"Reader"
		],
		"File" => [
			"File",
			"fs"
		],
		"Networking" => [
			"UDP",
			"DNS",
			"IPv4Participant",
			"eth"
		],
		"Crypto" => [
			"random",
			"aes",
			"hmac"
		]
	];

	return $module_order;
};
