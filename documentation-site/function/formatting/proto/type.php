<?php

return function($type_name) {
	$napc = napcdoc::documentation_get();

	$type = $napc["definitions"][$type_name];

	$ret = '<pre class="code">';

	if ($type["kind"] === "alias") {
		$ret .= napcdoc::createHTMLElement("span",
			["class" => "c-function"], "typedef "
		);

		$ret .= napcdoc::createHTMLElement("span",
			["class" => "c-identifier"],
			$type["alias_of"]
		);

		$ret .= " ";
		$ret .= napcdoc::createHTMLElement("span",
			["class" => "c-type"],
			$type_name
		);

		$ret .= ";";
	} else if ($type["kind"] === "struct") {
		$ret .= napcdoc::createHTMLElement("span",
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
			$ret .= "    ";

			if (!is_array($field["type"])) {
				$ret .= napcdoc::createHTMLElement("span",
					["class" => "c-type"],
					napcdoc::formatting_createLinkForCType($field["type"])
				);

				/** padding to align member types **/
				$delta = $pad - strlen($field["type"]);
				$ret .= str_repeat(" ", $delta);
				/** padding to align member types **/

				$ret .= " ";
				$ret .= napcdoc::createHTMLElement("span",
					["class" => "c-identifier"],
					$field["name"]
				);
				$ret .= ";\n";
			} else {
				$ret .= napcdoc::createHTMLElement("span",
					["class" => "c-type"],
					napcdoc::formatting_createLinkForCType($field["type"][0])
				);

				/** padding to align member types **/
				$delta = $pad - strlen($field["type"][0]);
				$ret .= str_repeat(" ", $delta);
				/** padding to align member types **/

				$ret .= " ";
				$ret .= napcdoc::createHTMLElement("span",
					["class" => "c-identifier"],
					$field["name"]
				);
				$ret .= napcdoc::createHTMLElement("span",
					["class" => "c-identifier"],
					"[".$field["type"][1]."]"
				);
				$ret .= ";\n";
			}
		}

		$ret .= "} ".napcdoc::createHTMLElement("span", ["class" => "c-type"], $type_name).";";
	} else if ($type["kind"] === "enum") {
		$ret .= napcdoc::createHTMLElement("span",
			["class" => "c-function"],
			"typedef enum"
		)." {\n";

		foreach ($type["values"] as $value) {
			$ret .= "    ".napcdoc::createHTMLElement("span",
				["class" => "c-identifier"],
				$value["name"]
			);

			if (strlen($value["value"])) {
				$ret .= " = ".napcdoc::createHTMLElement("span",
					["class" => "c-identifier"],
					$value["value"]
				);
			}

			$ret .= ",\n";
		}

		$ret .= "} ".napcdoc::createHTMLElement("span", 
			["class" => "c-type"],
			$type_name
		).";";
	}

	$ret .= "</pre>";

	return $ret;
};
