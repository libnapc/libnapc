<?php

return function($args, &$context) {
	return;

	foreach ($context["doc_blocks"] as &$doc_block) {
		if (napphp::arr_keyExists($doc_block, "@param")) {
			$doc_block["@param"] = napphp::util_arrayify($doc_block["@param"]);
		}

		if (napphp::arr_keyExists($doc_block, "@field")) {
			$doc_block["@field"] = napphp::util_arrayify($doc_block["@field"]);
		}

		if (napphp::arr_keyExists($doc_block, "@enum")) {
			$doc_block["@enum"] = napphp::util_arrayify($doc_block["@enum"]);
		}

		if (napphp::arr_keyExists($doc_block, "@changelog")) {
			$doc_block["@changelog"] = napphp::util_arrayify($doc_block["@changelog"]);
		}
	}
};
