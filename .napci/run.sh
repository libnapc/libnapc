#!/bin/bash -eux

./ci/run-v2.php

# Link build_files to napci server instance
ln -s ../build_files .napci/build_files
