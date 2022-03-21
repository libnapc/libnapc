<?php

return function($definition_name) {
	global $g__napc_doc_popover_definitions;

	if (!isset($g__napc_doc_popover_definitions)) {
		$g__napc_doc_popover_definitions = [];
	}

	if (!in_array($definition_name, $g__napc_doc_popover_definitions)) {
		$g__napc_doc_popover_definitions[] = $definition_name;
	}
};
