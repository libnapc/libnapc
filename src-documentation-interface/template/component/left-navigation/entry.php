<a
	href="<?php echo $__keys["href"];?>"
	<?php
		$classes = [];

		if (isset($__keys["active"]) && $__keys["active"]) {
			$classes[] = "active";
		}

		if (isset($__keys["strikethrough"]) && $__keys["strikethrough"]) {
			$classes[] = "strikethrough";
		}

		echo ' class="'.implode(" ", $classes).'"';

		if (isset($__keys["name"]) && $__keys["name"]) {
			echo ' name="'.$__keys["name"].'" ';
		}

		if (isset($__keys["data-attributes"])) {
			foreach ($__keys["data-attributes"] as $name => $value) {
				echo ' data-'.$name.'="'.$value.'" ';
			}
		}
	?>
>
	<?php
		$icon_name = "";
		$icon_size = 16;

		if (array_key_exists("icon", $__keys) && is_array($__keys["icon"])) {
			if (array_key_exists("size", $__keys["icon"])) {
				$icon_size = $__keys["icon"]["size"];
			}

			$icon_name = $__keys["icon"]["name"];
		} else {
			$icon_name = $__keys["icon"];
		}

		echo napcdoc::html_createSVGElement($icon_name, $icon_size, $icon_size);
	?>
	<div class="label-and-brief">
		<span class="label"><?php echo $__keys["label"]; ?></span>

		<?php
			if (isset($__keys["brief"]) && strlen($__keys["brief"])) {
				echo '<span class="brief">'.$__keys["brief"].'</span>';
			}
		?>
	</div>
</a>
