<?php

return function($v) {
	if (!is_array($v)) return [$v];

	return $v;
};
