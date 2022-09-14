<?php

if (in_array("hal", $__keys["flags"] ?? [])) {
	$type = $__keys["type"];

	if ($type === "fn") {
		$type = "function";
	}

	echo '<div class="warning-box hal">';
	echo napcdoc::html_createSVGElement("layers-triple", 24, 24);
	echo '	<div>';
	echo '		This '.$type.' is part of the hardware abstraction layer.';
	echo '	</div>';
	echo '</div>';
}
