<?php

return function() {
	$file_contents = "/*\n";

	foreach (file("LICENSE") as $line) {
		$file_contents .= "* $line";
	}

	$file_contents .= "*/\n";

	$file_contents .= XPHPUtils::libnapc_inlineHeaderIncludes(
		"build/napc.h", "build/"
	);

	if (is_file("build/__tests__/__tests__.h")) {
		$file_contents .= "\n\n";
		$file_contents .= file_get_contents("build/__tests__/__tests__.h");
	}

	file_put_contents("build/napc.h", $file_contents);
};
