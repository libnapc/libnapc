<?php

function libnapc_docMerge_getDocBlockByName($doc_blocks, $name) {
	foreach ($doc_blocks as $doc_block) {
		if (!napphp::arr_keyExists($doc_block, "@name")) continue;

		if ($doc_block["@name"] === $name) {
			return $doc_block;
		}
	}

	return false;
}

function libnapc_docMerge_createGeneralInfoByDocBlock($doc_block) {
	$general_info = [];

	if (napphp::arr_keyExists($doc_block, "@version")) {
		$general_info["version"] = $doc_block["@version"];
	}

	if (napphp::arr_keyExists($doc_block, "@deprecated")) {
		$general_info["deprecated"] = true;

		if (strlen($doc_block["@deprecated"])) {
			$general_info["deprecated_replacement"] = $doc_block["@deprecated"];
		}
	}

	if (napphp::arr_keyExists($doc_block, "@changelog")) {
		$changelog = [];

		foreach (napphp::util_arrayify($doc_block["@changelog"]) as $changelog_entry) {
			$tmp = napphp::str_split($changelog_entry, " ", 3);

			array_push($changelog, [
				"version" => $tmp[0],
				"date" => $tmp[1],
				"change" => $tmp[2]
			]);
		}

		$general_info["changelog"] = $changelog;
	}

	$additional_doc_block_mappings = [
		"@brief" => "brief",
		"@description" => "description",
		"@notes" => "notes",
		"@rationale" => "rationale",
		"@warning" => "warning",
		"@example" => "example"
	];

	foreach ($additional_doc_block_mappings as $doc_block_name => $general_info_name) {
		if (napphp::arr_keyExists($doc_block, $doc_block_name)) {
			$general_info[$general_info_name] = $doc_block[$doc_block_name];
		}
	}

	return $general_info;
}

return function($args, &$context) {
	fprintf(
		STDOUT,
		"%-45s %-15s %s\n",
		"Name", "Kind", "Module"
	);

	foreach ($context["c_symbols"] as $c_symbol_name => $c_symbol) {
		// Check if a doc-block with a @name exist
		// if not: skip this symbol (it becomes an undocumented symbol)
		$associated_doc_block = libnapc_docMerge_getDocBlockByName(
			$context["doc_blocks"], $c_symbol_name
		);

		if (!$associated_doc_block) {
			fprintf(
				STDERR,
				"C-Symbol '%s' has no matching doc-block, skipping.\n",
				napphp::terminal_colorString($c_symbol_name, "yellow")
			);

			continue;
		}

		// Determine module if doc-block comment does not
		// mention the associated module (@module)
		$associated_module = "";

		$padded_c_symbol_name = str_pad($c_symbol_name, 45, " ", STR_PAD_RIGHT);

		if (!napphp::arr_keyExists($associated_doc_block, "@module")) {
			// macros always need to be associated to a module
			// with @module
			if ($c_symbol["kind"] === "macro") {
				throw new CommandError(
					"Macro '$c_symbol_name' has no module associated with it."
				);
			}

			// napc_XXXX is always "Core" module
			// napc_XXXX_YYYY is always "XXXX" module
			$tmp = napphp::str_split($c_symbol_name, "_", 3);

			if (sizeof($tmp) === 3) {
				$associated_module = $tmp[1];
			} else {
				$associated_module = "Core";
			}
		} else {
			$associated_module = $associated_doc_block["@module"];
		}

		fprintf(
			STDOUT,
			"%-45s %-15s %s\n",
			$c_symbol_name,
			$c_symbol["kind"],
			$associated_module
		);

		$context["output"][$c_symbol_name] = [
			"name" => $c_symbol_name,
			"_associated_module" => $associated_module,
			"general_info" => libnapc_docMerge_createGeneralInfoByDocBlock(
				$associated_doc_block
			)
		];
	}
};
