<?php

if (isset($__keys["general_info"]["deprecated"]) && $__keys["general_info"]["deprecated"]) {
	$type = $__keys["type"];

	if ($type === "fn") $type = "function";

	$replace_with_text = "";

	if (isset($__keys["general_info"]["deprecated_replacement"])) {
		$replacement = $__keys["general_info"]["deprecated_replacement"];

		$link = napcdoc::html_createElement("a", [
			// no fixLink needed
			"href" => "./$replacement.html#$replacement"
		], $replacement);

		$replace_with_text = "Use $link instead of this $type.";
	}

	echo '<div class="warning-box">';
	echo napcdoc::html_createSVGElement("trash-can", 24, 24);
	echo '	<div>';
	echo '		<p>This '.$type.' is deprecated and will be removed in the next major version.</p>';
	echo '		'.$replace_with_text;
	echo '	</div>';
	echo '</div>';
}
