<?php

require_once __DIR__."/function/__autoload.php";

/**
 * only use sessions in dev build
 */
if (napcdoc::documentation_get()["build_constants"]["GIT_BRANCH"] === "dev") {
	session_start();

	if (isset($_POST["debug-git-branch"])) {
		$_SESSION["tmp-branch"] = $_POST["debug-git-branch"];
	}
}

$request = napcdoc::getRequest();

echo napcdoc::handleRequest($request);
