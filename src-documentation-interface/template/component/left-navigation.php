<div id="nd-left-navigation">
	<div class="search">
		<input placeholder="Please activate JavaScript" id="nd-local-search-input">
	</div>

	<div class="wrapper">
		<?php
			foreach ($__keys["entries"] as $entry) {
				echo napcdoc::site_renderTemplateFile(
					"component/left-navigation/entry",
					$entry
				);
			}
		?>
	</div>
</div>
