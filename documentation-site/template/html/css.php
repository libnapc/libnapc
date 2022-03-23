<?php

return function($keys) {
	if (napcdoc::opt_includeAssets()) {
		echo "<style>";
		echo napcdoc::getSiteStyle();
		echo "</style>";
	} else {
		$style = napcdoc::documentation_fixLink("style.css");
		$git_head = napcdoc::documentation_get()["build_constants"]["GIT_HEAD_HASH"];

		echo '<link rel="stylesheet" href="'.$style.'?v='.$git_head.'" type="text/css">';
	}
};
