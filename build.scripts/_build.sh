#!/bin/bash -eux

rm -rf arduino.tmp
mkdir arduino.tmp

mkdir -p dist

cp -r src arduino.tmp/src
cp dist/tmp_files/library.properties arduino.tmp
cp dist/tmp_files/napc_version.c arduino.tmp/src
cp dist/tmp_files/arduino_git_defines.h arduino.tmp/src/arduino_git_defines.h

if [ "$1" = "yes" ]; then
	mkdir arduino.tmp/src/__tests__

	for file in __tests__/_processed/*.c
	do
		cp "$file" arduino.tmp/src/__tests__
	done

	cp __tests__/__tests__.c arduino.tmp/src/__tests__
	cp __tests__/__tests__.h arduino.tmp/src/napc-tests.h
fi

cd arduino.tmp

zip -r ../arduino.tmp.zip .

cd ..

mv arduino.tmp.zip dist/libnapc-arduino.zip

rm -rf arduino.tmp
