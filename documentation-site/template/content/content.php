<?php

return function($keys) {

	$version = "DEV";

	if (is_file(__DIR__."/../../doc/dynamic/version.php")) {
		$version = file_get_contents(__DIR__."/../../doc/dynamic/version.php");
	}

?>
	<div id="napcdoc-content">
		<!-- wrapper is used to blur content when popover is active -->
		<!--<div id="napc-doc-content-wrapper">-->
			<?php echo $keys["content"] ?? "No content available"; ?>
			<div id="popover_padding_div"></div>
		<!--</div>-->

		<div class="page-info">
			<div class="version">
				Version of documentation: <?php echo $version; ?>
			</div>
			<div class="created-at">
				Documentation generated at <?php echo gmdate("d.m.Y H:i:s"); ?> (UTC)
			</div>
		</div>
	</div>
<?php
};
