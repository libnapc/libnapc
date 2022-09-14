<?php

return function($request_path) {
	$GLOBALS["global_napcdoc_request_path"] = $request_path;
};
