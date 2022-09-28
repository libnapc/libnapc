<?php

$has_left_navigation = sizeof($__keys["left-navigation"] ?? []) > 0;

?>
<div id="nd-header">
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

	<div class="menu-wrapper">
		<?php
			$pages = [
				[
					"label" => "Overview",
					"tablet_label" => "Overview",
					"mobile_label" => "Overview",
					"resource" => "home.html"
				],
				[
					"label" => "API Reference",
					"tablet_label" => "API",
					"mobile_label" => "API",
					"resource" => "api.html"
				],
				[
					"label" => "Documentation",
					"tablet_label" => "Docs",
					"mobile_label" => "Docs",
					"resource" => "documentation/index.html"
				],
				[
					"label" => "Releases",
					"tablet_label" => "Releases",
					"resource" => "releases.html"
				]
			];

			$request_path = napcdoc::http_getRequestPath();

			foreach ($pages as $page) {
				$classes = [];
				$is_active = $request_path === $page["resource"];

				if ($page["resource"] === "api.html") {
					if (napcdoc::util_startsWith($request_path, "definition/")) {
						$is_active = true;
					} else if (napcdoc::util_startsWith($request_path, "module/")) {
						$is_active = true;
					}
				} else if ($page["resource"] === "documentation/index.html") {
					if (napcdoc::util_startsWith($request_path, "document/")) {
						$is_active = true;
					}
				}

				$show_on_mobile = array_key_exists("mobile_label", $page);

				if ($is_active) {
					$classes[] = "active";
				}

				if (!$show_on_mobile) {
					$classes[] = "no-mobile";
				}

				// desktop
				$inner_html  = "<u>".$page["label"]."</u>";
				// tablet
				$inner_html .= "<b>".($page["tablet_label"] ?? $page["label"])."</b>";
				// mobile
				$inner_html .= "<i>".($page["mobile_label"] ?? $page["label"])."</i>";

				echo napcdoc::html_createElement("a", [
					"class" => implode(" ", $classes),
					"href" => napcdoc::site_link($page["resource"])
				], $inner_html);
			}
		?>
	</div>

	<div class="global-search-wrapper">
		<input id="nd-global-search-input" placeholder="Please activate JavaScript">
	</div>

	<div
		class="mobile-menu-wrapper <?php echo (!$has_left_navigation ? "empty" : ""); ?>"
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

<div id="nd-global-search-results">
	<div class="wrapper"></div>
</div>

<?php
	if ($has_left_navigation) {
		echo '<div id="nd-left-navigation">';

		echo '<div class="search">';
		echo '<input placeholder="Please activate JavaScript" id="nd-local-search-input">';
		echo '</div>';

		echo '<div class="wrapper">';

		foreach ($__keys["left-navigation"] as $entry) {
			echo napcdoc::site_renderTemplateFile("component/left-navigation/entry", $entry);
		}

		echo '</div>';
		echo '</div>';
	}
?>

<div id="nd-right-content" <?php echo (!$has_left_navigation ? 'class="no-left-side-navigation"' : ''); ?>>
	<div id="nd-mobile-navigation">
	<?php
		if ($has_left_navigation) {
			echo '<div class="nav-wrapper">';

			foreach ($__keys["left-navigation"] as $entry) {
				$entry["icon"] = [
					"name" => $entry["icon"],
					"size" => 20
				];
				echo napcdoc::site_renderTemplateFile("component/left-navigation/entry", $entry);
			}

			echo '</div>';
		}
	?>
	</div>

	<div class="wrapper">
		<?php echo $__keys["content"]; ?>
	</div>
</div>

<div id="nd-footer">
	<?php
		echo napcdoc::site_renderTemplateFile(
			"component/footer"
		);
	?>
</div>
