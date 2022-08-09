#!/bin/bash -eufx

ulimit -n 8192

./build.scripts/build.php

./ci.run-tests.sh

cd documentation-site/ && ./export.sh
