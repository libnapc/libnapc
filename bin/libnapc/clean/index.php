<?php

return [
	"description" => "Discard all generated build files",

	"run" => function() {
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/processed_files/");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/objects/");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/libnapc.a");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/bundles/");
	}
];
