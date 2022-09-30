<?php

return function($document_name) {
	$keys = [];

	$document_title = napcdoc::doc_getTitleOfDocument($document_name);

	$keys["site_title"] = "Documents › $document_title";

	$keys["left-navigation"] = napcdoc::leftnav_getDocuments(
		$document_name.".md"
	);

	$keys["content"] = napcdoc::site_renderMarkdownFile(
		"documents/$document_name"
	);

	return $keys;
};
