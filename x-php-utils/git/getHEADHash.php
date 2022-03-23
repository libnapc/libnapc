<?php

return function() {
	return trim(
		XPHPUtils::shell_exec("git rev-parse --abbrev-ref HEAD")
	);
};
