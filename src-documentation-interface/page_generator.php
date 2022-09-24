<?php

require_once __DIR__."/lib/load.php";

return function($request_path, $http_headers) {
	if ($request_path === "/") {
		$request_path = "/index.html";
	}

	napcdoc::http_setRequestPath($request_path);

	if (napphp::str_endsWith($request_path, ".html")) {
		$request_path_without_html = substr($request_path, 0, strlen($request_path) - 5);

		$html_template_keys = NULL;

		// handle documents
		if (napphp::str_startsWith($request_path, "/document/")) {
			$handler = require __DIR__."/handler/document.php";

			$document_name = substr($request_path_without_html, strlen("/document/"), -3);

			$html_template_keys = $handler($document_name);
		}
		// handle modules
		else if (napphp::str_startsWith($request_path, "/module/")) {
			$handler = require __DIR__."/handler/module.php";

			$module_name = substr($request_path_without_html, strlen("/module/"));

			$html_template_keys = $handler($module_name);
		}
		// handle definitions
		else if (napphp::str_startsWith($request_path, "/definition/")) {
			$handler = require __DIR__."/handler/definition.php";

			list(
				$unused1,
				$unused2,
				$module_name,
				$definition_name
			) = napphp::str_split($request_path_without_html, "/");

			$html_template_keys = $handler($module_name, $definition_name);
		}
		// must be a page then
		else {
			$page_name = substr($request_path_without_html, 1);

			$load_page = function($page_name) {
				$__keys = [];

				require __DIR__."/page/$page_name.php";

				return $__keys;
			};

			if (is_file(__DIR__."/page/$page_name.php")) {
				$html_template_keys = $load_page($page_name);
			}
		}

		if ($html_template_keys) {
			return [
				"headers" => [
					"Content-Type" => "text/html;charset=UTF-8"
				],
				"body" => napcdoc::site_renderTemplateFile("html", $html_template_keys)
			];
		}
	}
	// site styling
	else if ($request_path === "/site.css") {
		$handler = require __DIR__."/handler/site.css.php";

		return [
			"headers" => [
				"Content-Type" => "text/css;charset=UTF-8"
			],
			"body" => $handler($http_headers)
		];
	}
	// site styling
	else if ($request_path === "/verified.css") {
		return [
			"headers" => [
				"Content-Type" => "text/css;charset=UTF-8"
			],
			"body" => ""
		];
	}
	// site scripting
	else if ($request_path === "/site.js") {
		$handler = require __DIR__."/handler/site.js.php";

		return [
			"headers" => [
				"Content-Type" => "text/javascript;charset=UTF-8"
			],
			"body" => $handler($http_headers)
		];
	}
	// metadata
	else if ($request_path === "/metadata.xml") {
		$handler = require __DIR__."/handler/metadata.xml.php";

		return [
			"headers" => [
				"Content-Type" => "text/xml;charset=UTF-8"
			],
			"body" => $handler($http_headers)
		];
	}

	// if not handled by now, display 404
	$handler = require __DIR__."/handler/404.php";

	return [
		"headers" => [
			"Content-Type" => "text/html;charset=UTF-8"
		],
		"body" => $handler(
			// check if 404 was requested specificially
			// this is to prevent confusion between the real 404 page
			// and a page (erroneously) missing
			$request_path
		)
	];
};
