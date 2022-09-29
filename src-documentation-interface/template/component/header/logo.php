<div class="logo-wrapper">
	<?php
		echo napcdoc::html_createElement("a", [
			"href" => napcdoc::site_link("index.html")
		], napcdoc::html_createImageElement(
			"libnapc.png", [
				"height" => 50,
				"class" => "display-block-on-dark-theme"
			]
		));
	?>

	<?php
		echo napcdoc::html_createElement("a", [
			"href" => napcdoc::site_link("index.html")
		], napcdoc::html_createImageElement(
			"libnapc-alt.png", [
				"height" => 50,
				"class" => "display-block-on-light-theme"
			]
		));
	?>
</div>
