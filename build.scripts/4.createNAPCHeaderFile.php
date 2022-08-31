<?php

return function() {
	$file_contents = XPHPUtils::libnapc_inlineHeaderIncludes(
		"build/napc.h", "build/"
	);

	if (napphp::fs_isFile("build/__tests__/__tests__.h")) {
		$file_contents .= "\n\n";
		$file_contents .= napphp::fs_readFileString("build/__tests__/__tests__.h");
	}

	napphp::fs_writeFileStringAtomic("build/napc.h", $file_contents);
};
