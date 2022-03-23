<?php

return function() {
	$contents = file_get_contents("build/napc.h");
	$docs = [];

	for ($i = 0; $i < strlen($contents); ++$i) {
		if (substr($contents, $i, 4) === "/*!\n") {
			$tmp = "";

			for ($x = $i + 4; $x < strlen($contents); ++$x) {
				if (substr($contents, $x, 2) === "*/") break;

				$tmp .= $contents[$x];
			}

			$doc = explode("\n", $tmp);
			$doc = array_map("trim", $doc);
			$doc = array_filter($doc, function($line) {
				return substr($line, 0, 1) === "*";
			});

			$doc = array_map(function($line) {
				return substr($line, 2);
			}, $doc);

			$docs[] = $doc;
		}
	}

	$parse_doc_block = function($block) {
		$sections = [];
		$current_section = "";
		$current_section_value = "";

		$handle_end_of_section = function() use (&$current_section, &$current_section_value, &$sections) {
			if (strlen($current_section)) {
				if (array_key_exists("@$current_section", $sections)) {
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
			if (substr($line, 0, 1) === "@") {
				$handle_end_of_section();

				$single_line_section = !!strpos($line, " ");

				if ($single_line_section) {
					list($section, $value) = explode(" ", $line, 2);

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

	$out = array_map($parse_doc_block, $docs);

	file_put_contents(
		"build/doc/documentation.json", json_encode(
			$out, JSON_PRETTY_PRINT
		)
	);
};
