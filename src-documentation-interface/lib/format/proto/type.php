<?php

return function($type_name) {
	$napc = napcdoc::site_getDocumentation();

	$type = $napc["definitions"][$type_name];

	$ret = '<pre class="code-inside-content-box">';

	if ($type["kind"] === "alias") {
		$ret .= napcdoc::html_createElement("span",
			["class" => "c-function"], "typedef "
		);

		$ret .= napcdoc::html_createElement("span",
			["class" => "c-identifier"],
			$type["alias_of"]
		);

		$ret .= " ";
		$ret .= napcdoc::html_createElement("span",
			["class" => "c-type"],
			$type_name
		);

		$ret .= ";";
	} else if ($type["kind"] === "struct") {
		$ret .= napcdoc::html_createElement("span",
			["class" => "c-function"],
			"typedef struct"
		)." {";
		$ret .= "\n";

		/** padding to align member types **/
		$longest_field_type = "";

		foreach ($type["fields"] as $field) {
			$current_type = $field["type"];

			if (is_array($current_type)) $current_type = $current_type[0];

			if (strlen($current_type) > strlen($longest_field_type)) {
				$longest_field_type = $current_type;
			}
		}

		$pad = strlen($longest_field_type);
		/** padding to align member types **/

		foreach ($type["fields"] as $field) {
			$ret .= "    <span class=\"hljs-comment\">// ".$field["description"]."</span>\n";

			$ret .= "    ";

			if (!is_array($field["type"])) {
				$ret .= napcdoc::html_createElement("span",
					["class" => "c-type"],
					napcdoc::format_createLinkForCType($field["type"])
				);

				/** padding to align member types **/
				$delta = $pad - strlen($field["type"]);
				$ret .= str_repeat(" ", $delta);
				/** padding to align member types **/

				$ret .= " ";
				$ret .= napcdoc::html_createElement("span",
					["class" => "c-identifier"],
					$field["name"]
				);
				$ret .= ";\n";
			} else {
				$ret .= napcdoc::html_createElement("span",
					["class" => "c-type"],
					napcdoc::format_createLinkForCType($field["type"][0])
				);

				/** padding to align member types **/
				$delta = $pad - strlen($field["type"][0]);
				$ret .= str_repeat(" ", $delta);
				/** padding to align member types **/

				$ret .= " ";
				$ret .= napcdoc::html_createElement("span",
					["class" => "c-identifier"],
					$field["name"]
				);
				$ret .= napcdoc::html_createElement("span",
					["class" => "c-identifier"],
					"[".$field["type"][1]."]"
				);
				$ret .= ";\n";
			}
		}

		$ret .= "} ".napcdoc::html_createElement("span", ["class" => "c-type"], $type_name).";";
	} else if ($type["kind"] === "enum") {
		$ret .= napcdoc::html_createElement("span",
			["class" => "c-function"],
			"typedef enum"
		)." {\n";

		$n_values = sizeof($type["values"]);

		foreach ($type["values"] as $i => $value) {

			$ret .= "    <span class=\"hljs-comment\">// ".$value["description"]."</span>\n";


			$ret .= "    ".napcdoc::html_createElement("span",
				["class" => "c-identifier"],
				$value["name"]
			);

			if (strlen($value["value"])) {
				$ret .= " = ".napcdoc::html_createElement("span",
					["class" => "c-identifier"],
					$value["value"]
				);
			}

			// omit comma on last value
			if (($i + 1) < $n_values) {
				$ret .= ",";
			}

			$ret .= "\n";
		}

		$ret .= "} ".napcdoc::html_createElement("span", 
			["class" => "c-type"],
			$type_name
		).";";
	}

	$ret .= "</pre>";

	return $ret;
};
