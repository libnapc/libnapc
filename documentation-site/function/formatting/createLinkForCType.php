<?php

return function($type) {
	$napc = napcdoc::documentation_get();

	$clean = trim(str_replace(["*", "const"], "", $type));

	if (array_key_exists($clean, $napc["definitions"])) {
		$definition = $napc["definitions"][$clean];

		$popover = 'data-popover="'.$clean.'"';

		/**
		 * Used to pre-format fn/type definitions for popovers
		 */
		napcdoc::documentation_registerPopover($clean);

		return preg_replace("/$clean/", '<a '.$popover.' href="'.napcdoc::documentation_fixLink(
			napcdoc::documentation_getModuleOfDefinition($clean)."/$clean.html#$clean"
		).'">$0</a>', $type);
	}

	return $type;
};
