#!/bin/bash -euf

if [ ! -f "napc.h" ]; then
	printf "napc.h missing from current working directory\n"
	printf "Please place it here prior to installation\n"
	exit 2
elif [ ! -f "libnapc.a" ]; then
	printf "libnapc.a missing from current working directory\n"
	printf "Please execute ./compile.sh before continuing\n"
	exit 2
elif [ "$EUID" -ne 0 ]; then
	printf "Please run this script as root\n"

	exit 2
fi

HEADER_FILE_PATH="/usr/local/include/napc.h"
LIB_FILE_PATH="/usr/local/lib/libnapc.a"

printf "Attempting to install libnapc v%BC_RELEASE_VERSION%\n"

if [ -f "$HEADER_FILE_PATH" ] || [ -f "$LIB_FILE_PATH" ]; then
	printf "libnapc already installed\n"

	read -p "Do you want to overwrite the current installation of libnapc (y/n)? " choice

	case "$choice" in
		y|Y|yes|YES)
			echo "yes"
		;;

		*)
			printf "Cancelled\n"
			exit 2
		;;
	esac
fi

rm -f "$HEADER_FILE_PATH"
rm -f "$LIB_FILE_PATH"

cp "napc.h" "$HEADER_FILE_PATH"
cp "libnapc.a" "$LIB_FILE_PATH"

printf "Done!\n"
