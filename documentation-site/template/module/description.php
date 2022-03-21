<?php

return function($definition) {
	//echo '<h2 class="definition-section">Description</h2>';

	if (strlen($definition["general_info"]["description"] ?? "")) {
		echo napcdoc::formatting_multiLine($definition["general_info"]["description"]);
	} else {
		echo '<p><i>This '.$definition["type"].' does not have a description.</i></p>';
	}
};
