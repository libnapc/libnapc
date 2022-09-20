<?php

return [
	"description" => "Run linux tests.",

	"depends_on" => [
		"processed_files",
		"libnapc.a"
	],

	"run" => function($args) {
		//napphp::shell_execute(
		//	LIBNAPC_PROJECT_ROOT_DIR."/__tests__.linux/run.php"
		//);
	}
];
