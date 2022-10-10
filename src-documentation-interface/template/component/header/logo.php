<div class="logo-wrapper">
	<?php
		echo napcdoc::html_createElement("a", [
			"href" => napcdoc::site_link("index.html")
		], napcdoc::html_createImageElement(
			"libnapc.png", [
				"height" => 50,
				"class" => "dark-logo"
			]
		));

		echo napcdoc::html_createElement("a", [
			"href" => napcdoc::site_link("index.html")
		], napcdoc::html_createImageElement(
			"libnapc-c.png", [
				"height" => 50,
				"class" => "dark-logo-mobile"
			]
		));
	?>

	<?php
		echo napcdoc::html_createElement("a", [
			"href" => napcdoc::site_link("index.html")
		], napcdoc::html_createImageElement(
			"libnapc-alt.png", [
				"height" => 50,
				"class" => "light-logo"
			]
		));

		echo napcdoc::html_createElement("a", [
			"href" => napcdoc::site_link("index.html")
		], napcdoc::html_createImageElement(
			"libnapc-c-alt.png", [
				"height" => 50,
				"class" => "light-logo-mobile"
			]
		));
	?>
</div>
