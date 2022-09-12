<?php

return function($args, &$context) {
	$contents = $context["header"];

	$docs = [];

	for ($i = 0; $i < strlen($contents); ++$i) {
		if (substr($contents, $i, 4) === "/*!\n") {
			$tmp = "";

			for ($x = $i + 4; $x < strlen($contents); ++$x) {
				if (substr($contents, $x, 2) === "*/") break;

				$tmp .= $contents[$x];
			}

			$doc = napphp::str_split($tmp, "\n");
			$doc = napphp::arr_map($doc, "trim");
			$doc = napphp::arr_filter($doc, function($line) {
				return napphp::str_startsWith($line, "*");
			});

			$doc = napphp::arr_map($doc, function($line) {
				return substr($line, 2);
			});

			array_push($docs, $doc);
		}
	}

	$context["doc_block_comments"] = $docs;
};
