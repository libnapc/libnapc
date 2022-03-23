<?php

function doc_normalize_fixMacroType($type) {
	if ($type === "_cstring_") {
		return "const char *";
	}

	return $type;
}

function doc_normalize_extractMacroNames($napc) {
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

function doc_normalize_normalizeDocEntry($entry) {
	if (array_key_exists("@changelog", $entry)) {
		$entry["@changelog"] = XPHPUtils::arrayify($entry["@changelog"]);
	}

	if (array_key_exists("@param", $entry)) {
		$entry["@param"] = XPHPUtils::arrayify($entry["@param"]);
	}

	if (array_key_exists("@enum", $entry)) {
		$entry["@enum"] = XPHPUtils::arrayify($entry["@enum"]);
	}

	if (array_key_exists("@field", $entry)) {
		$entry["@field"] = XPHPUtils::arrayify($entry["@field"]);
	}

	return $entry;
}

function doc_normalize_getDocEntryByName($napc, $name) {
	foreach ($napc["doc"] as $entry) {
		if ($entry["@name"] === $name) {
			return doc_normalize_normalizeDocEntry($entry);
		}
	}

	fwrite(STDERR, "No entry for $name\n");
}

function doc_normalize_appendGeneralInfo($napc, &$entry, $name) {
	$meta = doc_normalize_getDocEntryByName($napc, $name);

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

return function($build_constants) {
	$napc = json_decode(file_get_contents("build/doc/napc_mapped.json"), true);
	$types_kind_map = json_decode(file_get_contents("build.scripts/doc/types.json"), true);
	$struct_members = json_decode(file_get_contents("build.scripts/doc/struct_members.json"), true);

	$mapped_napc = [];

	/**
	 * Functions
	 */
	$process_function = function($fn_name, $fn) use ($napc, &$mapped_napc) {
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

		$fn_meta = doc_normalize_getDocEntryByName($napc, $fn_name);

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

		doc_normalize_appendGeneralInfo($napc, $fn_doc, $fn_name);

		$mapped_napc["definitions"][$fn_name] = $fn_doc;
	};

	foreach ($napc["symbols"]["functions"] as $fn_name => $fn) {
		$process_function($fn_name, $fn);
	}

	/**
	 * Types
	 */
	$process_type = function($type_name, $type)
		use ($napc, &$mapped_napc, $types_kind_map, $struct_members)
	{

		if (!array_key_exists($type_name, $types_kind_map)) {
			fwrite(STDERR, "Unmapped type $type_name\n");
			return;
		}

		$type_meta = doc_normalize_getDocEntryByName($napc, $type_name);
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

		doc_normalize_appendGeneralInfo($napc, $type_doc, $type_name);

		$mapped_napc["definitions"][$type_name] = $type_doc;
	};

	foreach ($napc["symbols"]["types"] as $type_name => $type) {
		$process_type($type_name, $type);
	}

	/**
	 * Macros
	 */
	$process_macro = function($macro_name) use ($napc, &$mapped_napc) {
		$macro_doc = [
			"type" => "macro"
		];

		$macro_meta = doc_normalize_getDocEntryByName($napc, $macro_name);

		if ($macro_meta) {
			if (array_key_exists("@param", $macro_meta)) {
				$is_variadic = false;

				$macro_doc["params"] = [];

				foreach ($macro_meta["@param"] as $_) {
					$tmp = explode(" ", $_, 3);

					$macro_doc["params"][] = [
						"type" => doc_normalize_fixMacroType($tmp[0]),
						"name" => $tmp[1],
						"description" => $tmp[2]
					];

					if ($tmp[0] === "...") $is_variadic = true;
				}

				$macro_doc["variadic"] = $is_variadic;
			}
		}

		doc_normalize_appendGeneralInfo($napc, $macro_doc, $macro_name);

		$mapped_napc["definitions"][$macro_name] = $macro_doc;
	};

	foreach (doc_normalize_extractMacroNames($napc) as $macro_name) {
		$process_macro($macro_name);
	}

	$mapped_napc["modules"] = $napc["map"];

	/**
	 * Module intro texts
	 */
	$mapped_napc["modules_intro"] = [];

	$process_module_intro_text = function($doc_block) use (&$mapped_napc) {
		$module = explode(":", $doc_block["@name"], 2)[0];

		$mapped_napc["modules_intro"][$module] = $doc_block;
	};

	foreach ($napc["doc"] as $doc_block) {
		if (strpos($doc_block["@name"], ":") === false) continue;

		$process_module_intro_text($doc_block);
	}

	$mapped_napc["build_constants"] = $build_constants;
	$mapped_napc["release_files"] = [];

	$release_files = [
		"libnapc-aarch64.a"   => "build/lib/libnapc-aarch64.a",
		"libnapc-x86_64.a"    => "build/lib/libnapc-x86_64.a",
		"napc.h"              => "build/napc.h",
		"libnapc-arduino.zip" => "build/lib/libnapc-arduino.zip"
	];

	foreach ($release_files as $file_name => $path) {
		$mapped_napc["release_files"][] = [
			"name" => $file_name,
			"checksum" => hash_file("sha256", $path)
		];
	}

	file_put_contents(
		"build/doc/napc.json", json_encode($mapped_napc, JSON_PRETTY_PRINT)
	);
};
