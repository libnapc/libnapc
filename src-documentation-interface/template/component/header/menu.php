<div class="menu-wrapper">
	<?php
		$pages = [
			[
				"label" => "Overview",
				"icon" => "home",
				"tablet_label" => "Overview",
				"mobile_label" => "Overview",
				"resource" => "home.html"
			],
			[
				"label" => "API Reference",
				"icon" => "bolt",
				"tablet_label" => "API",
				"mobile_label" => "API",
				"resource" => "api.html"
			],
			[
				"label" => "Documentation",
				"icon" => "bookshelf",
				"tablet_label" => "Docs",
				"mobile_label" => "Docs",
				"resource" => "documentation/index.html"
			],
			[
				"label" => "Releases",
				"icon" => "package",
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

			$inner_html  = "";

			$inner_html .= napcdoc::html_createSVGElement($page["icon"], 18, 18);

			// desktop
			$inner_html .= "<u>".$page["label"]."</u>";
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
