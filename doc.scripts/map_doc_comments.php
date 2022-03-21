<?php

chdir(__DIR__."/..");

$napc = json_decode(file_get_contents("dist/doc/napc_unmapped.json"), true);
$types_kind_map = json_decode(file_get_contents("doc.scripts/definitions/types.json"), true);
$struct_members = json_decode(file_get_contents("doc.scripts/definitions/struct_members.json"), true);

function arrayify($v) {
	if (!is_array($v)) return [$v];

	return $v;
}

function extract_macro_names() {
	global $napc;

	$ret = [];

	foreach ($napc["map"] as $module_name => $definitions) {
		foreach ($definitions as $definition) {
			if (substr($definition, 0, 2) === "m:") {
				$ret[] = substr($definition, 2);
			}
		}
	}

	return $ret;
}

function normalize_doc_entry($entry) {
	if (array_key_exists("@changelog", $entry)) {
		$entry["@changelog"] = arrayify($entry["@changelog"]);
	}

	if (array_key_exists("@param", $entry)) {
		$entry["@param"] = arrayify($entry["@param"]);
	}

	if (array_key_exists("@enum", $entry)) {
		$entry["@enum"] = arrayify($entry["@enum"]);
	}

	if (array_key_exists("@field", $entry)) {
		$entry["@field"] = arrayify($entry["@field"]);
	}

	return $entry;
}

function get_doc_entry_by_name($name) {
	global $napc;

	foreach ($napc["doc"] as $entry) {
		if ($entry["@name"] === $name) {
			return normalize_doc_entry($entry);
		}
	}

	fwrite(STDERR, "No entry for $name\n");
}

$mapped_napc = [];

function append_general_info(&$entry, $name) {
	$meta = get_doc_entry_by_name($name);

	if (!$meta) return;

	$documentation = [];

	if (array_key_exists("@version", $meta)) {
		$documentation["version"] = $meta["@version"];
	}

	if (array_key_exists("@deprecated", $meta)) {
		$documentation["deprecated"] = true;

		if (strlen($meta["@deprecated"])) {
			$documentation["deprecated_replacement"] = $meta["@deprecated"];
		}
	}

	if (array_key_exists("@changelog", $meta)) {
		$changelog = [];

		foreach ($meta["@changelog"] as $changelog_entry) {
			$tmp = explode(" ", $changelog_entry, 3);

			$changelog[] = [
				"version" => $tmp[0],
				"date" => $tmp[1],
				"change" => $tmp[2]
			];
		}

		$documentation["changelog"] = $changelog;
	}

	if (array_key_exists("@brief", $meta)) {
		$documentation["brief"] = $meta["@brief"];
	}

	if (array_key_exists("@description", $meta)) {
		$documentation["description"] = $meta["@description"];
	}

	if (array_key_exists("@notes", $meta)) {
		$documentation["notes"] = $meta["@notes"];
	}

	if (array_key_exists("@rationale", $meta)) {
		$documentation["rationale"] = $meta["@rationale"];
	}

	if (array_key_exists("@warning", $meta)) {
		$documentation["warning"] = $meta["@warning"];
	}

	if (array_key_exists("@example", $meta)) {
		$documentation["example"] = $meta["@example"];
	}

	$entry["general_info"] = $documentation;
}

function process_function($fn_name, $fn) {
	global $mapped_napc;

	$fn_doc = [
		"type" => "fn",
		"return" => [
			"type" => $fn["return_type"],
			"description" => ""
		],
		"params" => $fn["params"],
		"flags" => $fn["flags"]
	];

	// inject empty description into every param
	foreach ($fn_doc["params"] as &$fn_doc_param) {
		$fn_doc_param["description"] = "";
	}

	$fn_meta = get_doc_entry_by_name($fn_name);

	if ($fn_meta) {
		if (array_key_exists("@param", $fn_meta)) {
			foreach ($fn_meta["@param"] as $fn_meta_param) {
				$tmp = explode(" ", $fn_meta_param, 2);

				foreach ($fn_doc["params"] as &$fn_doc_param) {
					if ($fn_doc_param["name"] === $tmp[0]) {
						$fn_doc_param["description"] = $tmp[1];
					}
				}
			}
		}

		if (array_key_exists("@return", $fn_meta)) {
			$fn_doc["return"]["description"] = $fn_meta["@return"];
		}
	}

	append_general_info($fn_doc, $fn_name);

	$mapped_napc["definitions"][$fn_name] = $fn_doc;
}

foreach ($napc["symbols"]["functions"] as $fn_name => $fn) {
	process_function($fn_name, $fn);
}

function process_type($type_name, $type) {
	global $mapped_napc, $types_kind_map, $struct_members;

	if (!array_key_exists($type_name, $types_kind_map)) {
		fwrite(STDERR, "Unmapped type $type_name\n");
		return;
	}

	$type_meta = get_doc_entry_by_name($type_name);
	$type_kind = $types_kind_map[$type_name];
	$type_doc = [
		"type" => "type"
	];

	switch ($type_kind) {
		case "opaque": {
			$type_doc["kind"] = "opaque";
		} break;

		case "struct": {
			$type_doc["kind"] = "struct";

			if (array_key_exists($type_name, $struct_members)) {
				$type_doc["fields"] = [];

				foreach ($struct_members[$type_name] as $field_name => $field_type) {
					$field_description = "";

					if ($type_meta && array_key_exists("@field", $type_meta)) {
						foreach ($type_meta["@field"] as $_) {
							$tmp = explode(" ", $_, 2);

							if ($tmp[0] === $field_name) {
								$field_description = $tmp[1];
							}
						}
					}

					$type_doc["fields"][] = [
						"name" => $field_name,
						"type" => $field_type,
						"description" => $field_description
					];
				}
			}
		} break;

		case "enum": {
			$type_doc["kind"] = "enum";

			$enum_values = [];

			if ($type_meta && array_key_exists("@enum", $type_meta)) {
				foreach ($type_meta["@enum"] as $_) {
					$tmp = explode(" ", $_, 2);

					$enum_values[] = [
						"name" => $tmp[0],
						"value" => "",
						"description" => $tmp[1] ?? ""
					];
				}
			}

			$type_doc["values"] = $enum_values;
		} break;

		default: {
			$type_doc["kind"] = "alias";
			$type_doc["alias_of"] = $type_kind;
		}
	}

	append_general_info($type_doc, $type_name);

	$mapped_napc["definitions"][$type_name] = $type_doc;
}

foreach ($napc["symbols"]["types"] as $type_name => $type) {
	process_type($type_name, $type);
}

function fixMacroType($type) {
	if ($type === "_cstring_") {
		return "const char *";
	}

	return $type;
}

function process_macro($macro_name) {
	global $mapped_napc;

	$macro_doc = [
		"type" => "macro"
	];

	$macro_meta = get_doc_entry_by_name($macro_name);

	if ($macro_meta) {
		if (array_key_exists("@param", $macro_meta)) {
			$is_variadic = false;

			$macro_doc["params"] = [];

			foreach ($macro_meta["@param"] as $_) {
				$tmp = explode(" ", $_, 3);

				$macro_doc["params"][] = [
					"type" => fixMacroType($tmp[0]),
					"name" => $tmp[1],
					"description" => $tmp[2]
				];

				if ($tmp[0] === "...") $is_variadic = true;
			}

			$macro_doc["variadic"] = $is_variadic;
		}
	}

	append_general_info($macro_doc, $macro_name);

	$mapped_napc["definitions"][$macro_name] = $macro_doc;
}

foreach (extract_macro_names() as $macro_name) {
	process_macro($macro_name);
}

$mapped_napc["modules"] = $napc["map"];
$mapped_napc["modules_intro"] = [];

function process_module_intro_text($doc_block) {
	global $mapped_napc;

	$module = explode(":", $doc_block["@name"], 2)[0];

	$mapped_napc["modules_intro"][$module] = $doc_block;
}

foreach ($napc["doc"] as $doc_block) {
	if (strpos($doc_block["@name"], ":") === false) continue;

	process_module_intro_text($doc_block);
}

file_put_contents(
	"dist/napc.json", json_encode($mapped_napc, JSON_PRETTY_PRINT)
);
