<?php

if ($__keys["type"] === "warning") {
	$icon = "alert-circle";
	$color = "orange";
	$title = "Caution";
} else if ($__keys["type"] === "deprecation") {
	$icon = "trash-can";
	$color = "red";
	$title = "Deprecation Notice";
} else if ($__keys["type"] === "info") {
	$icon = "info";
	$color = "blue";
	$title = "Note";
} else if ($__keys["type"] === "code") {
	$icon = "code-braces";
	$color = "gray";
	$title = "Declaration";
} else if ($__keys["type"] === "code-example") {
	$icon = "code-tags";
	$color = "gray";
	$title = "Example Usage";
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
	<div class="content-box-content"><?php echo $__keys["content"]; ?></div>
</div>
