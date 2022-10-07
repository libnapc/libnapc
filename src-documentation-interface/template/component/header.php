<div id="nd-header">
	<?php echo napcdoc::site_renderTemplateFile("component/header/logo"); ?>

	<?php echo napcdoc::site_renderTemplateFile("component/header/menu"); ?>

	<?php echo napcdoc::site_renderTemplateFile("component/header/theme-switcher"); ?>

	<div class="global-search-wrapper">
		<input id="nd-global-search-input" placeholder="Please activate JavaScript">
	</div>

	<div
		class="mobile-menu-wrapper <?php echo (!$__keys["has_left_navigation"] ? "empty" : ""); ?>"
		id="toggle-mobile-menu">
		<div class="menu-open">
			<?php
				echo napcdoc::html_createSVGElement("menu", 32, 32);
			?>
		</div>

		<div class="menu-close">
			<?php
				echo napcdoc::html_createSVGElement("close", 32, 32);
			?>
		</div>
	</div>
</div>
