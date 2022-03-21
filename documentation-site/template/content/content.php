<?php

return function($keys) {
	$get_version = require __DIR__."/../../doc/version.php";
?>
	<div id="napcdoc-content">
		<?php echo $keys["content"] ?? "No content available"; ?>

		<div id="popover_padding_div"></div>

		<div class="page-info">
			<div class="version">
				Version of documentation: <?php echo $get_version(); ?>
			</div>
			<div class="created-at">
				Documentation generated at <?php echo gmdate("d.m.Y H:i:s"); ?> (UTC)
			</div>
		</div>
	</div>
<?php
};
