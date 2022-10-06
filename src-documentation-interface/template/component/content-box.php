<?php

$content = $__keys["content"];

if ($__keys["type"] === "warning") {
	$icon = "alert-circle";
	$color = "orange";
	$title = "Caution";
} else if ($__keys["type"] === "deprecation") {
	$icon = "trash-can";
	$color = "orange";
	$title = "Deprecation Notice";
} else if ($__keys["type"] === "info") {
	$icon = "info";
	$color = "blue";
	$title = "Note";
} else if ($__keys["type"] === "declaration") {
	$icon = "code-braces";
	$color = "gray";
	$title = "Declaration";
} else if ($__keys["type"] === "hal") {
	$icon = "layers-triple";
	$color = "green";
	$title = "HAL";
} else if ($__keys["type"] === "code") {
	$icon = "code-tags";
	$color = "gray";
	$language = $__keys["code_language"] ?? "none";
	$title = "Code ($language)";

	$content  = "";
	$content .= "<pre class=\"code-inside-content-box hljs\" data-language=\"$language\">";
	$content .= htmlspecialchars($__keys["code"]);
	$content .= "</pre>";
}

?>
<div class="content-box color-<?php echo $color; ?>">
	<div class="content-box-head">
		<?php
			echo napcdoc::html_createSVGElement(
				"$icon", 12, 12
			);
		?>
		<div><?php echo $title; ?></div>
	</div>
	<div class="content-box-content"><?php echo $content; ?></div>
</div>
