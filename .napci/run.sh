#!/bin/bash -eux

./ci/run.php

# Link build_files to napci server instance
ln -s ../build_files .napci/build_files
