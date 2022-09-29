<div id="nd-footer">
	<a class="logo-wrapper">
		<?php
			echo napcdoc::html_createImageElement(
				"nap.software.png", [
					"height" => 32
				]
			);
		?>
	</a>

	<div class="delimiter"></div>

	<a class="github-wrapper" href="https://github.com/libnapc/libnapc" target="_blank">
		<?php
			echo napcdoc::html_createImageElement(
				"github.png", [
					"height" => 20
				]
			);
		?>
	</a>

	<div class="info-wrapper">
		<?php
			echo napcdoc::site_getDocumentation()["build_constants"]["RELEASE_VERSION"];
		?>
	</div>
</div>
