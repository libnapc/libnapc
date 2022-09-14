<?php

return function($document_name) {
	$keys = [];

	$keys["left-navigation"] = napcdoc::leftnav_getDocuments(
		$document_name.".md"
	);

	$keys["content"] = napcdoc::site_renderMarkdownFile(
		"documents/$document_name"
	);

	return $keys;
};
