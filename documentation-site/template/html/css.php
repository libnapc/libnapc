<?php

return function($keys) {
	if (napcdoc::opt_includeAssets()) {
		echo "<style>";
		echo napcdoc::getSiteStyle();
		echo "</style>";
	} else {
		$style = napcdoc::documentation_fixLink("style.css");

		echo '<link rel="stylesheet" href="'.$style.'" type="text/css">';
	}
};
