<?php

return function($keys) {
?><!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<?php
		echo napcdoc::renderFile("html/head", $keys);

		echo napcdoc::renderFile("html/css", $keys);

		foreach ($keys["meta_og_keys"] as $key => $value) {
			echo '<meta property="og:'.$key.'" content="'.$value.'">';
		}
	?>

	<meta property="og:image" content="https://libnapc.nap.software/static/banner.png">
</head>
<!-- body { display: block; } will be set after HTML loaded -->
<body class="theme-dark git-branch-<?php echo $keys["_build_constants"]["GIT_BRANCH"]; ?>" style="display: none;">

	<div id="napcdoc-layout-background"></div>

	<div id="napcdoc-layout-global-search">
		<input
			id="napcdoc-global-search-input"
			placeholder="Please activate JavaScript">
	</div>

	<div id="napcdoc-layout-global-search-results">
		<a href="">
			result 1
		</a>

		<a href="">
			result 2
		</a>
	</div>

	<div id="napcdoc-layout-logo">
		<?php
			$logo_src = "image/libnapc-logo-min.png";

			if (in_array($keys["_build_constants"]["GIT_BRANCH"], ["nightly", "dev"])) {
				$logo_src = "image/libnapc-logo-".$keys["_build_constants"]["GIT_BRANCH"]."-min.png";
			}

			echo napcdoc::createHTMLElement("a", [
				"class" => "logo-wrapper",
				"href" => napcdoc::documentation_fixLink("index.html")
			], napcdoc::createHTMLElement("img", [
				"src" => napcdoc::imageToBase64URI($logo_src),
				"alt" => "NAPC Software Documentation Logo",
				"height" => 50
			]));
		?>
	</div>

	<div id="napcdoc-layout-navigation-header">
		<?php echo napcdoc::renderFile("navigation/header", $keys); ?>
	</div>

	<div id="napcdoc-layout-navigation">
		<?php echo napcdoc::renderFile("navigation/navigation", $keys); ?>
	</div>

	<div id="napcdoc-layout-content-header">
		<?php echo napcdoc::renderFile("content/header", $keys); ?>
	</div>

	<div id="napcdoc-layout-content">
		<?php echo napcdoc::renderFile("content/content", $keys); ?>
	</div>

	<div id="napcdoc-layout-mobile-navigation-toggle">
		<?php
			echo napcdoc::createSVGElement("menu", 32, 32, [
				"class" => "open-menu"
			]);

			echo napcdoc::createSVGElement("close", 32, 32, [
				"class" => "close-menu"
			]);
		?>
	</div>

	<div id="napcdoc-layout-mobile-navigation">
		<?php echo napcdoc::renderFile("navigation/mobile", $keys); ?>
	</div>

	<?php
		if (isset($keys["background_icon"]) && strlen($keys["background_icon"])) {
			echo napcdoc::createHTMLElement("div", [
				"id" => "napcdoc-layout-background-icon"
			], napcdoc::createSVGElement($keys["background_icon"], 256, 256));
		}
	?>

	<?php
		echo napcdoc::renderFile("html/popover_definitions", $keys);
	?>

	<script>
		window.napcdoc_request_uri = <?php echo json_encode($_SERVER["REQUEST_URI"]); ?>;
	</script>

	<?php
		echo napcdoc::renderFile("html/js", $keys);
	?>

	<style>body { display: block !important; }</style>
</body>
</html>
<?php
};
