<?php

return [
	"description" => "Export documentation.",

	"depends_on" => [
		"napc.json"
	],

	"creates" => "documentation.tar.gz",

	"run" => function($args) {
		napphp::proc_changeWorkingDirectory(LIBNAPC_PROJECT_ROOT_DIR."/documentation-site/");
		napphp::shell_execTransparently("./export.sh");
	}
];
