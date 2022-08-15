#!/bin/bash -eux

./.napci/pre.sh
./ci/run.sh
./.napci/post.sh

#
# place files into correct directory
#

# build_files
mv dist/* .napci/build_files.tmp
mv .napci/build_files.tmp .napci/build_files

# upload_files
cd .napci/upload_files.tmp/

ln -s ../build_files/libnapc-arduino.zip .
ln -s ../build_files/libnapc-linux-aarch64.a .
ln -s ../build_files/libnapc-linux-x86_64.a .
ln -s ../build_files/napc.h .

cd ../../

mv .napci/upload_files.tmp .napci/upload_files
