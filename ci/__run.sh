#!/bin/bash -eufx

./bin/libnapc.php clean
./bin/libnapc.php preprocess
./bin/libnapc.php compile
./bin/libnapc.php link
./bin/libnapc.php run-unit-tests
./bin/libnapc.php run-linux-tests

./bin/libnapc.php bundle

# generate documentation
./bin/libnapc.php doc-clean
./bin/libnapc.php doc-gen-ast
./bin/libnapc.php doc-extract-c-symbols
./bin/libnapc.php doc-extract-doc-blocks
./bin/libnapc.php doc-merge
./bin/libnapc.php doc-map
./bin/libnapc.php doc-finalize
./bin/libnapc.php doc-export

rm -rf build_files/documentation_files
mkdir build_files/documentation_files

# unpack documentation tarball
tar -xzvf build_files/documentation.tar.gz -C build_files/documentation_files
