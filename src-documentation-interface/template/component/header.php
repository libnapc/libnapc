<div id="nd-header">
	<?php echo napcdoc::site_renderTemplateFile("component/header/logo"); ?>

	<?php echo napcdoc::site_renderTemplateFile("component/header/menu"); ?>

	<?php echo napcdoc::site_renderTemplateFile("component/header/theme-switcher"); ?>

	<?php echo napcdoc::site_renderTemplateFile("component/header/global-search"); ?>

	<?php
		echo napcdoc::site_renderTemplateFile("component/header/mobile-hamburger-icon", [
			"has_left_navigation" => $__keys["has_left_navigation"]
		]);
	?>
</div>
