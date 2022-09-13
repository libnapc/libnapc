#!/bin/bash -eufx

./bin/libnapc.php clean
./bin/libnapc.php preprocess
./bin/libnapc.php compile
./bin/libnapc.php link
./bin/libnapc.php run-unit-tests

# temporarily allow unbound variables
set +u

# Create ALL output files when running on private CI-server instance
if [ -n "$NAPCI_GIT_BRANCH" ]; then
	./bin/libnapc.php bundle
	./bin/libnapc.php doc-clean
	./bin/libnapc.php doc-gen-ast
	./bin/libnapc.php doc-extract-c-symbols
	./bin/libnapc.php doc-extract-doc-blocks
	./bin/libnapc.php doc-merge
	./bin/libnapc.php doc-map
	./bin/libnapc.php doc-finalize
	./bin/libnapc.php doc-export

	mkdir build_files/documentation_files

	tar -xzvf build_files/documentation.tar.gz -C build_files/documentation_files
fi

set -u
