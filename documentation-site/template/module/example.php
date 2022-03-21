<?php

function test($text) {

	//$text = preg_replace("/napc__UDPSocket/", "<a>$0</a>", $text);

	return $text;
}

return function($definition) {
	if (strlen($definition["general_info"]["example"] ?? "")) {
		echo '<div class="module-section">';
		echo napcdoc::renderFile("module/section-title", [
			"label" => "Example Usage"
		]);

		echo '<pre class="code hljs">'.test($definition["general_info"]["example"]).'</pre>';
		echo '</div>';
	}
};
