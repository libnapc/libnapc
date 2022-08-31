<?php

return function() {
	$documentation = napphp::fs_readFileJSON("build/doc/documentation.json", false);
	$modules = napphp::fs_readFileJSON("build/doc/modules_symbols_map.json", false);
	$symbols = napphp::fs_readFileJSON("build/doc/symbols.tagged.json", false);
	$types = [];

	$types_map = napphp::fs_readFileJSON("build.scripts/doc/types.json");
	$struct_members = napphp::fs_readFileJSON("build.scripts/doc/struct_members.json");

	foreach ($symbols->types as $type) {
		if (!napphp::arr_keyExists($types_map, $type)) {
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

	napphp::fs_writeFileJSONAtomic(
		"build/doc/napc_mapped.json", $out, true
	);
};
