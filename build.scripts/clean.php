#!/usr/bin/env php
<?php

require_once __DIR__."/../x-php-utils/load.php";

chdir(__DIR__."/../");

XPHPUtils::shell_assertSystemCall("rm -rf dist");
XPHPUtils::shell_assertSystemCall("rm -rf dist.tmp");
XPHPUtils::shell_assertSystemCall("rm -rf build");
