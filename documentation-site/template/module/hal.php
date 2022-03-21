<?php

return function($definition) {
	if (in_array("hal", $definition["flags"] ?? [])) {
		$type = napcdoc::documentation_readableDefinitionType($definition);

		echo '<div class="hal-box">';
		echo napcdoc::createSVGElement("layers-triple", 24, 24);
		echo '	<div>';
		echo '		This '.$type.' utilizes part of the hardware abstraction layer.';
		echo '	</div>';
		echo '</div>';
	}
};
