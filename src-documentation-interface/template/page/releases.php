<style>
div.releases div.flex-table-row.header {
	text-transform: uppercase;
	color: var(--base-text-color-dimmed-2);
}

div.releases div.flex-table-row-cell.filename {
	flex-basis: 170px !important;
}

div.releases div.flex-table-row-cell.checksum {
	font-family: "PT Mono";
	display: flex;
	align-items: center;
}

span.libnapc-checksums-verified {
	margin-left: 7px;
	display: none;
}

span.libnapc-checksums-verified svg path {
	fill: #00ff02;
}

div.releases div.flex-table-row-cell.filesize {
	flex-basis: 170px !important;
} 
</style>
<h1>Releases</h1>

<div class="releases">

	<div class="flex-table">
		<div class="flex-table-row header">
			<div class="flex-table-row-cell filename">Filename</div>
			<div class="flex-table-row-cell">SHA256-Checksum</div>
			<div class="flex-table-row-cell filesize">Size</div>
		</div>

		<?php
			$files = napcdoc::site_getDocumentation()["files"];

			$release_version = napcdoc::site_getDocumentation()["build_constants"]["RELEASE_VERSION"];

			foreach ($files as $filename => $meta) {
		?>

			<div class="flex-table-row">
				<div class="flex-table-row-cell filename">
					<a href="https://libnapc.nap-software.com/v<?php echo $release_version; ?>/download/<?php echo $filename; ?>" target="_blank">
						<?php echo $filename; ?>
					</a>
				</div>
				<div class="flex-table-row-cell checksum">
					<?php echo $meta["checksum"]; ?>
					<span class="libnapc-checksums-verified">
						<?php
							echo napcdoc::html_createSVGElement(
								"check-decagram", 16, 16
							);
						?>
					</span>
				</div>
				<div class="flex-table-row-cell filesize">
					<?php echo number_format($meta["size"] / 1000, 2); ?> kB
				</div>
			</div>
		<?php
			}
		?>
	</div>

</div>

<!--
  This is only needed to show a "verified" icon once the checksums have been verified
  -->
<link rel="stylesheet" property="stylesheet" href="verified.css" type="text/css">
