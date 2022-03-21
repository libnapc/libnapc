<?php

return function($keys) {
	if (napcdoc::opt_includeAssets()) {
		echo '<script>';
		echo napcdoc::getSiteScript();
		echo '</script>';
	} else {
		$script = napcdoc::documentation_fixLink("script.js");

		echo '<script src="'.$script.'" type="text/javascript"></script>';
	}
};
