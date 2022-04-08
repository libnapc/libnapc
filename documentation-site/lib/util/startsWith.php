<?php

return function($str, $needle) {
	return substr($str, 0, strlen($needle)) === $needle;
};
