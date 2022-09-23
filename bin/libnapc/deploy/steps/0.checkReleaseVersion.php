<?php

return function($args, &$context) {
	if ($context["dry_run"]) return;

	$release_version = $context["build_constants"]["RELEASE_VERSION"];

	if (sizeof(napphp::str_split($release_version, ".")) !== 3) {
		throw new CommandError(
			"Refusing to deploy invalid release version '$release_version'."
		);
	}
};
