<h1>
<?php
	echo napcdoc::site_shortenDefinitionName($__keys["definition_name"]);
?>
</h1>

<?php

if (strlen($__keys["general_info"]["description"] ?? "")) {
	echo napcdoc::format_multiLine($__keys["general_info"]["description"]);
} else {
	echo '<p><i>This '.$__keys["type"].' does not have a description.</i></p>';
}

?>
