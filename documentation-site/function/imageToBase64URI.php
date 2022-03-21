<?php

return function($path) {
	$contents = file_get_contents(__DIR__."/../assets/$path");
	$base64 = base64_encode($contents);

	return "data:image/png;base64,$base64";
};
