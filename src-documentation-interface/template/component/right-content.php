<div
	id="nd-right-content"
	<?php echo (!$__keys["has_left_navigation"] ? 'class="no-left-side-navigation"' : ''); ?>
>

	<div id="nd-mobile-navigation">
	<?php
		if ($__keys["has_left_navigation"]) {
			echo '<div class="nav-wrapper">';

			foreach ($__keys["mobile_navigation_menu"] as $entry) {
				$entry["icon"] = [
					"name" => $entry["icon"],
					"size" => 20
				];

				echo napcdoc::site_renderTemplateFile(
					"component/left-navigation/entry", $entry
				);
			}

			echo '</div>';
		}
	?>
	</div>

	<div class="wrapper">
		<?php echo $__keys["content"]; ?>
	</div>
</div>
