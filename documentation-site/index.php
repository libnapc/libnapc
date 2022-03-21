<?php

require_once __DIR__."/function/__autoload.php";

$request = napcdoc::getRequest();

echo napcdoc::handleRequest($request);
