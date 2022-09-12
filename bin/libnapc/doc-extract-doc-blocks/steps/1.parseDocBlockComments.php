<?php

function libnapc_docExtractDocBlocks_parseDocBlock($block) {
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
}

return function($args, &$context) {
	$context["doc_blocks"] = napphp::arr_map(
		$context["doc_block_comments"], "libnapc_docExtractDocBlocks_parseDocBlock"
	);
};
