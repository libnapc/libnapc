<?php

return function($modules) {
	$module_order = [
		"General" => [
			"Core",
			"env",
			"OSTimer",
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
			"sha",
			"aes",
			"hmac"
		]
	];

	return $module_order;
};
