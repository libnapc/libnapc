<?php

return function($definition) {
	if (isset($definition["general_info"]["deprecated"]) && $definition["general_info"]["deprecated"]) {
		$type = napcdoc::documentation_readableDefinitionType($definition);
		$replace_with_text = "";

		if (isset($definition["general_info"]["deprecated_replacement"])) {
			$replacement = $definition["general_info"]["deprecated_replacement"];

			$link = napcdoc::createHTMLElement("a", [
				// no fixLink needed
				"href" => "./$replacement.html#$replacement"
			], $replacement);

			$replace_with_text = "Use $link instead of this $type.";
		}

		echo '<div class="warning-box">';
		echo napcdoc::createSVGElement("trash-can", 24, 24);
		echo '	<div>';
		echo '		<p>This '.$type.' is deprecated and will be removed in the next major version.</p>';
		echo '		'.$replace_with_text;
		echo '	</div>';
		echo '</div>';
	}
};
