<?php

return [
	"description" => "Remove all build files that are used for the online documentation.",

	"run" => function() {
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/clang-ast.json");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/c-symbols.json");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/doc-blocks.json");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/napc-definitions.json");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/napc-mapped.json");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/napc.json");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/documentation_files");
		napphp::fs_delete(LIBNAPC_BUILD_FILES_DIR."/documentation.tar.gz");
	}
];
