<?php

return function() {
	$documentation = json_decode(file_get_contents("build/doc/documentation.json"));
	$modules = json_decode(file_get_contents("build/doc/modules_symbols_map.json"));
	$symbols = json_decode(file_get_contents("build/doc/symbols.tagged.json"));
	$types = [];

	$types_map = json_decode(file_get_contents("build.scripts/doc/types.json"), true);
	$struct_members = json_decode(file_get_contents("build.scripts/doc/struct_members.json"), true);

	foreach ($symbols->types as $type) {
		if (!array_key_exists($type, $types_map)) {
			echo "Unmapped type $type\n";

			continue;
		}

		$type_kind = $types_map[$type];

		if ($type_kind === "struct") {
			$types[$type] = [
				"kind" => "struct",
				"members" => $struct_members[$type]
			];
		} else if ($type_kind === "opaque") {
			$types[$type] = [
				"kind" => "opaque"
			];
		} else if ($type_kind === "enum") {
			$types[$type] = [
				"kind" => "enum"
			];
		} else {
			$types[$type] = [
				"kind" => "alias",
				"alias_of" => $type_kind
			];
		}
	}

	unset($symbols->types);

	$symbols->types = $types;

	$out = [
		"doc" => $documentation,
		"symbols" => $symbols,
		"map" => $modules
	];

	file_put_contents(
		"build/doc/napc_mapped.json", json_encode(
			$out, JSON_PRETTY_PRINT
		)
	);
};
