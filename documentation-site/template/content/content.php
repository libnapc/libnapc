<?php

return function($keys) {
	$build_constants = napcdoc::documentation_get()["build_constants"];
?>
	<div id="napcdoc-content">
		<?php echo $keys["content"] ?? "No content available"; ?>

		<div id="popover_padding_div"></div>

		<div class="page-info">
			<div class="version">
				Version: <?php echo $build_constants["RELEASE_VERSION"]; ?>
			</div>
			<div class="created-at">
				Documentation generated at <?php echo gmdate("d.m.Y H:i:s"); ?> (UTC)
			</div>
		</div>
	</div>
<?php
};
