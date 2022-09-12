<?php

function libnapc_docMerge_getDescriptionByName(
	$type, $doc_block, $requested_name
) {
	$debug_name = napphp::terminal_colorString($doc_block["@name"] ?? "n/a", "yellow");

	if (!napphp::arr_keyExists($doc_block, "@$type")) {
		fwrite(
			STDERR,
			"(error) Unable to get $type description (@name=$debug_name): no @$type doc-block.\n"
		);

		return "error=1";
	}

	$entries = napphp::util_arrayify($doc_block["@$type"]);

	foreach ($entries as $entry) {
		$tmp = napphp::str_split($entry, " ", 2);
		$doc_block_entry_name = $tmp[0];

		if ($requested_name === $doc_block_entry_name) {
			return $tmp[1] ?? "";
		}
	}

	fwrite(
		STDERR,
		"(error) Unable to get $type description (@name=$debug_name): unable to find '$requested_name'.\n"
	);

	return "error=2";
}

return [
	"description" => "Merge C-Symbols with information provided by doc-block comments.",

	"depends_on" => [
		"c-symbols.json",
		"doc-blocks.json"
	],
	"creates"    => "napc-definitions.json",

	"run" => function($args) {
		$c_symbols_array = napphp::fs_readFileJSON(LIBNAPC_BUILD_FILES_DIR."/c-symbols.json");
		$c_symbols       = [];

		foreach ($c_symbols_array as $c_symbol) {
			$c_symbols[$c_symbol["name"]] = $c_symbol;
		}

		$doc_blocks_array = napphp::fs_readFileJSON(LIBNAPC_BUILD_FILES_DIR."/doc-blocks.json");
		$doc_blocks       = [];

		foreach ($doc_blocks_array as $doc_block) {
			if (!napphp::arr_keyExists($doc_block, "@name")) {
				fwrite(STDERR, "WARNING: doc-block without @name\n");
				continue;
			}

			$doc_blocks[$doc_block["@name"]] = $doc_block;
		}

		$context = [
			"output"     => [],
			"c_symbols"  => $c_symbols,
			"doc_blocks" => $doc_blocks
		];

		command_runSteps("doc-merge", $args, $context);

		napphp::fs_writeFileJSONAtomic(
			LIBNAPC_BUILD_FILES_DIR."/napc-definitions.json", $context["output"], true
		);
	}
];
