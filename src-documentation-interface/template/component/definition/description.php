<style>
div.definition-header {
	display: flex;
	align-items: center;
	margin-bottom: 15px; /* from <h1> style */
}

div.definition-header div.left {
	font-size: 27px; /* from <h1> style */
	font-weight: bold;
}

div.definition-header div.right {
	margin-left: auto;
	display: flex;
	align-items: center;
}

div.definition-header div.right div.napcdoc-svg-image {
	margin-right: 5px;
}

div.definition-header div.right div.napcdoc-svg-image svg path {
	fill: currentColor;
}

@media only screen and (max-width: 1000px) {
	div.definition-header {
		flex-direction: column;
		align-items: flex-start;
	}

	div.definition-header div.right {
		margin-left: unset;
		margin-top: 15px;
	}
}
</style>

<div class="definition-header">
	<div class="left">
		<?php
			echo napcdoc::site_shortenDefinitionName($__keys["definition_name"]);
		?>
	</div>

	<?php
		if (array_key_exists("origin", $__keys)) {
	?>
		<div class="right">
			<?php
				echo napcdoc::html_createSVGElement(
					"text-box-search-outline", 18, 18
				);
			?>
			<?php
				$origin = $__keys["origin"];
				$release_version = napcdoc::site_getDocumentation()["build_constants"]["RELEASE_VERSION"];
				$branch_name = "v$release_version";

				// use 'main' if $release_version is not a proper version number
				if (napphp::str_contains($branch_name, "main")) {
					$branch_name = "main";
				}

				echo napcdoc::html_createElement("a", [
					"href" => "https://github.com/libnapc/libnapc/blob/$branch_name/src/".$origin["path"]."#L".$origin["line"],
					"target" => "_blank"
				], "View definition on github");
			?>
		</div>
	<?php
		}
	?>
</div>

<?php

if (strlen($__keys["general_info"]["description"] ?? "")) {
	echo napcdoc::format_multiLine($__keys["general_info"]["description"]);
} else if (strlen($__keys["general_info"]["brief"] ?? "")) {
	echo napcdoc::format_multiLine($__keys["general_info"]["brief"]);
} else {
	echo '<p><i>This '.$__keys["type"].' does not have a description.</i></p>';
}

?>
