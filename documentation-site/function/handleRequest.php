<?php

return function($request) {
	$keys = [];

	$keys["_build_constants"] = napcdoc::documentation_get()["build_constants"];

	if ($request["module"]) {
		if (!$request["definition"]) {
			$keys["title"] = $request["module"];
		} else {
			$keys["title"] = $request["definition"];
		}

		$keys["navigation"] = [
			"entries" => napcdoc::navigation_module($request["module"], $request["definition"]),
			"header" => [
				"menu" => [
					"Navigation" => [[
						"link" => napcdoc::documentation_fixLink("./index.html"),
						"icon" => "book-open",
						"label" => "Go back to reference home"
					]]
				]
			]
		];

		if ($request["definition"]) {
			$keys["navigation"]["header"]["menu"]["Navigation"][] = [
				"link" => "../".$request["module"].".html",
				"icon" => "module_icon/".$request["module"],
				"label" => "Go back to ".$request["module"]." module"
			];
		}

		$keys["background_icon"] = "module_icon/".$request["module"];
		$keys["meta_og_keys"] = napcdoc::meta_module($request["module"], $request["definition"]);

		$keys["content"] = napcdoc::content_module($request["module"], $request["definition"]);
		$keys["content_header"] = napcdoc::contentheader_module($request["module"], $request["definition"]);
	} else {
		$requested_file = basename($_SERVER["REQUEST_URI"]);

		ob_start();

		$keys["title"] = "???";
		$icon = "???";

		if ($requested_file === "index.html") {
			$keys["title"] = "Reference Home";
			$icon = "book-open";

			require __DIR__."/../doc/content/home.php";
		} else if ($requested_file === "install.html") {
			$keys["title"] = "Installation Guide";
			$icon = "cog";

			require __DIR__."/../doc/content/install.php";
		} else if ($requested_file === "downloads.html") {
			$keys["title"] = "Downloads";
			$icon = "download";

			require __DIR__."/../doc/content/downloads.php";
		} else if ($requested_file === "style.css") {
			header("Content-Type: text/css;charset=UTF-8");
			ob_end_clean();
			echo napcdoc::getSiteStyle();
			exit();
		} else if ($requested_file === "script.js") {
			header("Content-Type: text/javascript;charset=UTF-8");
			ob_end_clean();
			echo napcdoc::getSiteScript();
			exit();
		}

		$keys["content"] = ob_get_contents();
		ob_clean();

		$keys["navigation"] = [
			"entries" => napcdoc::navigation_home(),
			"header" => [
				"menu" => [
					"Navigation" => [[
						"link" => "./index.html",
						"icon" => "book-open",
						"label" => "Reference Home"
					], [
						"link" => "./install.html",
						"icon" => "cog",
						"label" => "Installation Guide"
					], [
						"link" => "./downloads.html",
						"icon" => "download",
						"label" => "Downloads"
					]]
				]
			]
		];

		$keys["meta_og_keys"] = [];

		$keys["content_header"] =  [
			"icon" => $icon,
			"title" => $keys["title"],
			"description" => ""
		];
	}

	return napcdoc::renderFile("site", $keys);
};
