<?php

return function($definition) {
	switch ($definition["type"]) {
		case "fn": return "function";
		case "type": return "type";
		case "macro": return "macro";
	}

	return "???";
};
