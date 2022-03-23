<?php

return function($keys) {
	if (napcdoc::opt_includeAssets()) {
		echo '<script>';
		echo napcdoc::getSiteScript();
		echo '</script>';
	} else {
		$script = napcdoc::documentation_fixLink("script.js");
		$git_head = napcdoc::documentation_get()["build_constants"]["GIT_HEAD_HASH"];

		echo '<script src="'.$script.'?v='.$git_head.'" type="text/javascript"></script>';
	}
};
