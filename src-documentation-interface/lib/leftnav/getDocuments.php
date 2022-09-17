<?php

return function($request_document = "") {
	$nav = [];

	$entries = napphp::fs_scandirRecursive(__DIR__."/../../content/documents");
	$entries = array_filter($entries, function($document) {
		return $document["type"] === "file";
	});

	$documents = array_map(function($document) {
		$lines = napphp::fs_file($document["path"]);

		return [
			"title" => substr($lines[0], 2),
			"name" => $document["basename"]
		];
	}, $entries);

	foreach ($documents as $document) {
		$nav[] = [
			"label" => $document["title"],
			"icon" => "book-open",
			"href" => napcdoc::site_link("document/".$document["name"].".html"),
			"name" => $document["name"],
			"active" => $document["name"] === $request_document
		];
	}

	return $nav;
};
