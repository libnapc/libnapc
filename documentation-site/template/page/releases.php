<style>
div.releases div.flex-table-row.header {
	text-transform: uppercase;
	color: rgba(255, 255, 255, .3);
}

div.releases div.flex-table-row-cell.filename {
	flex-basis: 250px !important;
} 
</style>
<h1>Releases</h1>

<div class="releases">

	<div class="flex-table">
		<div class="flex-table-row header">
			<div class="flex-table-row-cell filename">Filename</div>
			<div class="flex-table-row-cell">SHA256-Checksum</div>
			<div class="flex-table-row-cell">Size</div>
		</div>

		<?php
			$files = napcdoc::site_getDocumentation()["files"];

			$release_version = napcdoc::site_getDocumentation()["build_constants"]["RELEASE_VERSION"];

			foreach ($files as $filename => $meta) {
		?>

			<div class="flex-table-row">
				<div class="flex-table-row-cell filename">
					<a href="https://libnapc.nap-software.com/v<?php echo $release_version; ?>/<?php echo $filename; ?>" target="_blank">
						<?php echo $filename; ?>
					</a>
				</div>
				<div class="flex-table-row-cell">
					<?php echo $meta["checksum"]; ?>
				</div>
				<div class="flex-table-row-cell">
					<?php echo number_format($meta["size"] / 1000, 2); ?> kB
				</div>
			</div>
		<?php
			}
		?>
	</div>

</div>
