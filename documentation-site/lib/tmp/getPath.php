<?php

return function() {
	foreach (getallheaders() as $name => $value) {
		if (strtolower($name) === "x-napdoc-set-tmp-directory") {
			return $value;
		}
	}

	return __DIR__."/../../tmp/";
};
