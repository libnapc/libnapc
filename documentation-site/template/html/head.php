<?php

return function($keys) {
	if (isset($keys["title"])) {
		echo "<title>libnapc — ".$keys["title"]."</title>";
	} else {
		echo "<title>libnapc</title>";
	}

	if (isset($keys["favicon"])) {
		//echo '<link rel="icon" type="image/png" sizes="16x16" href="'.inline_png($favicon).'">';
	}
};
