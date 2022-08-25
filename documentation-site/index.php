<?php

//ini_set("display_errors", 1);
//ini_set("display_startup_errors", 1);
//error_reporting(E_ALL);

$uname = strtolower(php_uname());

// allow for node-sass because dart-sass does not
// offer an ARM version (yet)
if (is_file("/usr/local/bin/node-sass")) {
	define("LIBNAPC_SASS_BIN", "/usr/local/bin/node-sass");
} else if (strpos($uname, "linux") !== false) {
	define("LIBNAPC_SASS_BIN", __DIR__."/bin/linux/sass/sass");
} else {
	define("LIBNAPC_SASS_BIN", __DIR__."/bin/macos/sass/sass");
}

define("LIBNAPC_ASSETS", __DIR__."/assets/");

require_once __DIR__."/lib/load.php";

napcdoc::site_createCSS();
napcdoc::site_createJS();

$site_errors = napcdoc::site_registerError();

if (sizeof($site_errors)) {
	echo 'There was a problem generating the site: ';

	foreach ($site_errors as $error) {
		echo $error;
	}

	exit();
}

$request_path = napcdoc::http_getRequestPath();

if ($request_path === "site.css") {
	header("Content-Type: text/css;charset=UTF-8");
	echo implode("\n", napcdoc::site_registerCSSCode());
	exit();
} else if ($request_path === "site.js") {
	header("Content-Type: text/javascript;charset=UTF-8");
	echo implode("\n", napcdoc::site_registerJSCode());
	exit();
} else if ($request_path === "metadata.xml") {
	header("Content-Type: text/xml;charset=UTF-8");

	$build_constants = napcdoc::site_getDocumentation()["build_constants"];

	echo '<?xml version="1.0" encoding="UTF-8"?>'."\n";
	echo '<metadata>'."\n";
	echo "\t".'<build_constants>'."\n";

	foreach ($build_constants as $key => $value) {
		// skip BUILD_DATE
		if ($key === "BUILD_DATE") continue;

		echo "\t\t".'<build_constant>'."\n";
		echo "\t\t\t".'<name>'.$key.'</name>'."\n";
		echo "\t\t\t".'<value>'.$value.'</value>'."\n";
		echo "\t\t".'</build_constant>'."\n";
	}

	echo "\t".'</build_constants>'."\n";

	$release_files = napcdoc::site_getDocumentation()["files"];

	echo "\t".'<release_files>'."\n";

	foreach ($release_files as $filename => $meta) {
		echo "\t\t".'<release_file>'."\n";
		echo "\t\t\t<name>".$filename."</name>\n";
		echo "\t\t\t<size>".$meta["size"]."</name>\n";
		echo "\t\t\t<checksum>".$meta["checksum"]."</checksum>\n";
		echo "\t\t".'</release_file>'."\n";
	}

	echo "\t".'</release_files>'."\n";

	echo '</metadata>'."\n";

	exit();
}

if (substr($request_path, -5, 5) === ".html") {
	$page_name = substr($request_path, 0, strlen($request_path) - 5);
	$keys = [];

	if (napcdoc::util_startsWith($page_name, "document/")) {
		$document_name = substr($page_name, strlen("document/"), -3);

		$keys["left-navigation"] = napcdoc::leftnav_getDocuments(
			$document_name.".md"
		);
		$keys["content"] = napcdoc::site_renderMarkdownFile(
			"documents/$document_name"
		);
	} else if (napcdoc::util_startsWith($page_name, "module/")) {
		$module_name = substr($page_name, strlen("module/"));

		$keys["left-navigation"] = napcdoc::leftnav_getDefinitionsOfModule(
			$module_name, ""
		);
		$keys["content"] = "<h1>$module_name</h1>";

		$modules_intro = napcdoc::site_getDocumentation()["modules_intro"];

		if (array_key_exists($module_name, $modules_intro)) {
			$keys["content"] .= napcdoc::site_renderMarkdown(
				$modules_intro[$module_name]["@description"] ?? ""
			);

			if (array_key_exists("@example", $modules_intro[$module_name])) {
				$keys["content"] .= '<pre class="code hljs">';
				$keys["content"] .= htmlspecialchars($modules_intro[$module_name]["@example"]);
				$keys["content"] .= '</pre>';
			}
		}
	} else if (napcdoc::util_startsWith($page_name, "definition/")) {
		list($unused, $module_name, $definition_name) = explode("/", $page_name);

		$keys["left-navigation"] = napcdoc::leftnav_getDefinitionsOfModule(
			$module_name, $definition_name
		);
		$keys["content"] = napcdoc::site_renderTemplateFile(
			"component/definition/index", [
				"definition_name" => $definition_name
			]
		);
	} else {
		$load_page = function($page_name) {
			$__keys = [];

			require __DIR__."/page/$page_name.php";

			return $__keys;
		};

		$keys = $load_page($page_name);
	}

	echo napcdoc::site_renderTemplateFile("html", $keys);
}
