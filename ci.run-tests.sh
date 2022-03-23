#!/bin/bash -eufx

gcc \
	-Wall \
	-Wpedantic \
	-Wextra \
	-Ldist/ \
	-Idist/ \
	ci.run-tests.c \
	"-lnapc-$(uname -m)" \
	-o \
	ci.run-all-tests

valgrind \
	--leak-check=full \
	--show-reachable=yes \
	--error-exitcode=1 \
	./ci.run-all-tests

rm -f ./ci.run-all-tests
