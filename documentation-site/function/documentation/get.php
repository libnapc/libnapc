<?php

return function() {
	static $doc = NULL;

	if (!$doc) {
		$doc = json_decode(
			file_get_contents(__DIR__."/../../doc/napc.json"), true
		);
	}

	return $doc;
};
