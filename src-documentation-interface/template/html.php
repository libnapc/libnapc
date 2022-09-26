<?php
$body_classes = [];

if (!isset($__keys["left-navigation"])) {
	$body_classes[] = "no-left-side-navigation";
}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title></title>

	<link rel="stylesheet" href="<?php echo napcdoc::site_link("site.css"); ?>?no_cache=<?=time();?>">
</head>
<body class="theme-dark <?php echo implode(" ", $body_classes); ?>">
	<?php
		echo napcdoc::site_renderTemplateFile("site", $__keys);
	?>

	<script>
		window.napcdoc_request_uri = "<?php echo napcdoc::http_getRequestPath(); ?>";
	</script>

	<script src="<?php echo napcdoc::site_link("site.js"); ?>"></script>
</body>
</html>
