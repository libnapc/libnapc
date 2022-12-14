#!/bin/bash -eufx

./bin/libnapc.php clean
./bin/libnapc.php preprocess
./bin/libnapc.php compile --with-tests
./bin/libnapc.php link
./bin/libnapc.php run-unit-tests
./bin/libnapc.php run-linux-tests

./bin/libnapc.php bundle
