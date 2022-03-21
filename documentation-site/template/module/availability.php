<?php

return function($definition) {
	return;

	echo '<div class="module-section">';
	echo napcdoc::renderFile("module/section-title", [
		"label" => "Availability"
	]);
	echo '</div>';
};
