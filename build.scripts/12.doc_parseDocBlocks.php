<?php

return function() {
	$contents = napphp::fs_readFileString("build/napc.h");
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

			$docs[] = $doc;
		}
	}

	$parse_doc_block = function($block) {
		$sections = [];
		$current_section = "";
		$current_section_value = "";

		$handle_end_of_section = function() use (&$current_section, &$current_section_value, &$sections) {
			if (strlen($current_section)) {
				if (napphp::arr_keyExists($sections, "@$current_section")) {
					$section_value = $sections["@$current_section"];

					if (is_array($section_value)) {
						$sections["@$current_section"][] = $current_section_value;
					} else {
						$sections["@$current_section"] = [
							$section_value, $current_section_value
						];
					}
				} else {
					$sections["@$current_section"] = $current_section_value;
				}
			}

			$current_section = "";
			$current_section_value = "";
		};

		foreach ($block as $line) {
			// begin of section
			if (napphp::str_startsWith($line, "@")) {
				$handle_end_of_section();

				$single_line_section = !!strpos($line, " ");

				if ($single_line_section) {
					list($section, $value) = napphp::str_split($line, " ", 2);

					$current_section = substr($section, 1);
					$current_section_value = $value;

					$handle_end_of_section();
				} else {
					$current_section = substr($line, 1);
				}
			} else if (strlen($current_section)) {
				if (!strlen($current_section_value)) {
					$current_section_value .= $line;
				} else {
					$current_section_value .= "\n".$line;
				}
			}
		}

		$handle_end_of_section();

		return $sections;
	};

	$out = napphp::arr_map($docs, $parse_doc_block);

	napphp::fs_writeFileJSONAtomic(
		"build/doc/documentation.json", $out, true
	);
};
