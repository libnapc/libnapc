<?php

/**
 * Used to "autoload" functions
 */
class napcdoc {
	static $loaded_functions = [];

	static public function __callStatic($name, $args) {
		if (array_key_exists($name, self::$loaded_functions)) {
			return call_user_func_array(self::$loaded_functions[$name], $args);
		}

		$name2 = str_replace("_", "/", $name);

		$fn_path = __DIR__."/$name2.php";

		if (!is_file($fn_path)) {
			throw new Exception("Undefined function $name (path=$fn_path).");
		}

		$fn = require $fn_path;

		if (!is_callable($fn)) {
			throw new Exception("Imported function not callable.");
		}

		self::$loaded_functions[$name] = $fn;

		return call_user_func_array($fn, $args);
	}
}
