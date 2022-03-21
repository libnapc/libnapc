<?php

$checksums = require __DIR__."/../checksums.php";

?>

<style>
div.flex-table.releases div.flex-table-row-cell.checksum {
	color: rgba(255, 255, 255, .3);
	text-transform: uppercase;
	font-size: 11px;
}
</style>

<div class="flex-table releases">
	<div class="flex-table-row">
		<div class="flex-table-row-cell">
			Filename
		</div>
		<div class="flex-table-row-cell">
			Checksum (SHA256)
		</div>
	</div>

	<?php
		foreach ($checksums as $file => $checksum) {
			echo '<div class="flex-table-row">';
			echo '	<div class="flex-table-row-cell">';
			echo '		<a href="/download/'.$file.'">'.$file.'</a>';
			echo ' </div>';
			echo '	<div class="flex-table-row-cell checksum">';
			echo '		'.$checksum;
			echo '	</div>';
			echo '</div>';
		}
	?>
</div>
