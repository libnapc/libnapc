<?php

return function() {
	$ret = "";

	$ret .= '(function(){';
	$ret .= 'window.napcdoc = JSON.parse(';
	$ret .= json_encode(json_encode([
		"assets" => [
			"svg" => napcdoc::assets_getSVGAssets()
		]
	], JSON_PRETTY_PRINT));
	$ret .= ');';
	$ret .= 'var tmp = JSON.parse('.json_encode(json_encode(napcdoc::documentation_get())).');';
	$ret .= 'window.napcdoc.definitions = tmp.definitions;';
	$ret .= 'window.napcdoc.modules = tmp.modules;';
	$ret .= 'window.napcdoc.lib = {};';
	$ret .= '})();';

	foreach (napcdoc::assets_getJSAssets() as $name => $contents) {
		$ret .= "/** $name **/\n";
		$ret .= "(function() {\n";
		$ret .= "try {";
		$ret .= $contents;
		$ret .= "} catch (error) {";
		$ret .= "console.error('Error in JS asset ' + ".json_encode($name)." + ':');";
		$ret .= "console.error(error);";
		$ret .= "console.error('---');";
		$ret .= "}";
		$ret .= "})();";
	}

	$ret .= "/** __init.js **/\n";
	$ret .= "setTimeout(function() {\n";
	$ret .= file_get_contents(__DIR__."/../assets/js/__init.js");
	$ret .= "}, 1);";

	return $ret;
};
