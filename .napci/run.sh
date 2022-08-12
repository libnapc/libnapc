#!/bin/bash -eufx

# Increase limit of open files at a time
ulimit -n 8192

# Build library
./build.scripts/build.php

# Run unit tests
./ci.run-tests.sh

# Build documentation
cd documentation-site/ && ./export.sh

# Unpack documentation
cd ..

rm -rf dist/documentation.tmp
mkdir dist/documentation.tmp

tar \
	-xzvf dist/doc.tar.gz \
	-C dist/documentation.tmp

rm -rf dist/documentation
mv dist/documentation.tmp dist/documentation
