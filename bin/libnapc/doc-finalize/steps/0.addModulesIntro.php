<?php

return function($args, &$context) {
	$modules_intro = [];

	foreach ($context["doc_blocks"] as $doc_block) {
		$name = $doc_block["@name"];
		$tmp = napphp::str_split($name, ":", 2);

		if (sizeof($tmp) !== 2) continue;

		$modules_intro[$tmp[0]] = $doc_block;
	}

	$context["output"]["modules_intro"] = $modules_intro;
};
