<?php

return function($file) {
	return napcdoc::site_renderMarkdown(
		file_get_contents(__DIR__."/../../content/$file.md")
	);
};
