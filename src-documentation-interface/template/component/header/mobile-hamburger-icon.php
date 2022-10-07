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
