<?php

return function() {
	foreach (getallheaders() as $name => $value) {
		if (strtolower($name) === "x-optimized-output") {
			return false;
		}
	}

	return true;
};
