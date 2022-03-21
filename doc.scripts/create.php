#!/usr/bin/env php
<?php
require_once __DIR__."/../php.lib/exec_or_die.php";

chdir(__DIR__."/..");

exec_or_die("rm -rf dist/doc");
exec_or_die("mkdir dist/doc");
exec_or_die("php doc.scripts/create_symbols_file.php");
exec_or_die("php doc.scripts/tag_functions.php");
exec_or_die("php doc.scripts/parse_doc_comments.php");
exec_or_die("php doc.scripts/map_symbols.php");

$documentation = json_decode(file_get_contents("dist/doc/documentation.json"));
$modules = json_decode(file_get_contents("dist/doc/modules.json"));
$symbols = json_decode(file_get_contents("dist/doc/symbols.tagged.json"));
$types = [];

$types_map = json_decode(file_get_contents("doc.scripts/definitions/types.json"), true);
$struct_members = json_decode(file_get_contents("doc.scripts/definitions/struct_members.json"), true);

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
	"dist/doc/napc_unmapped.json", json_encode(
		$out, JSON_PRETTY_PRINT
	)
);

exec_or_die("php doc.scripts/map_doc_comments.php");

//`rm -rf dist/doc`;
