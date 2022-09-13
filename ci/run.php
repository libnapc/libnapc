#!/usr/bin/env php
<?php

chdir(__DIR__."/../");

system("./ci/__run.sh", $exit_code);

exit($exit_code);
