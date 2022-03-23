#!/bin/bash -eux

rm -rf arduino.tmp
mkdir arduino.tmp

mkdir -p dist

cp -r src arduino.tmp/src

# remove source files
find arduino.tmp -name '*.c' -delete

# copy processed source files
cp -r dist/processed_src/*.c arduino.tmp/src/
cp -r dist/processed_src/*.cpp arduino.tmp/src/

cp dist/tmp_files/library.properties arduino.tmp

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
