#!/bin/bash -eufx

gcc \
	-Wall \
	-Wpedantic \
	-Wextra \
	-Ldist/ \
	-Idist/ \
	ci/run-tests.c \
	"-lnapc-local" \
	-o \
	ci/ci.run-all-tests

valgrind \
	--leak-check=full \
	--show-reachable=yes \
	--error-exitcode=1 \
	./ci/ci.run-all-tests

rm -f ./ci/ci.run-all-tests
