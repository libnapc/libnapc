<style>
div.landing {
	display: flex;
	align-items: center;
	justify-content: center;
	flex-direction: column;
}

div.landing h1 {
	font-size: 20px !important;
	font-weight: 400;
}

div.landing h1 i {
	color: var(--base-text-color-dimmed-2);
	font-style: normal;
}

div.landing {
	max-width: 100%;
	max-height: 100%;
	overflow: hidden;
}

div.landing a {
	color: white;
	display: flex;
	align-items: center;
	justify-content: center;
	background-image: linear-gradient(15deg, var(--text-gradient-color-1), var(--text-gradient-color-2));
	background-color: var(--text-gradient-color-1);
	font-size: 17px;
	padding: 7px 23px;
	border-radius: 40px;
	text-decoration: none;
	margin-top: 30px;
	z-index: 10;
	position: relative;
	text-shadow: 0px 2px 2px rgba(9, 8, 14, .35);
}

@keyframes landing-logo-animation {
	0%, 100% {
		transform: translateY(0px);
	}

	50% {
		transform: translateY(7px);
	}
}

@keyframes landing-logo-shadow-animation {
	0%, 100% {
		opacity: 0;
	}

	50% {
		opacity: .3;
	}
}

div.landing img {
	animation-name: landing-logo-animation;
	animation-duration: 2.5s;
	animation-timing-function: ease-in-out;
	animation-iteration-count: infinite;
	animation-delay: 1s;

	position: relative;
	z-index: 2;
}

div.landing div.img-shadow {
	width: 200px;
	height: 50px;
	border-radius: 100%;

	box-shadow: 0px -100px 40px var(--base-text-color-dimmed-2);
	position: relative;
	top: 40px;


	animation-name: landing-logo-shadow-animation;
	animation-duration: 2.5s;
	animation-timing-function: ease-in-out;
	animation-iteration-count: infinite;
	animation-delay: 1s;

	opacity: 0;
}
</style>

<div class="landing">
	<?php

	echo napcdoc::html_createImageElement("libnapc-c.png", [
		"height" => 300,
		"class" => "big-c display-block-on-dark-theme"
	]);

	echo napcdoc::html_createImageElement("libnapc-c-alt.png", [
		"height" => 300,
		"class" => "big-c display-block-on-light-theme"
	]);

	?>

	<div class="img-shadow"></div>

	<h1><i>Run, Test & Debug on Linux.</i> Deploy on Arduino.</h1>

	<a href="document/1.gettingStarted.md.html">Jump right in!</a>
</div>
