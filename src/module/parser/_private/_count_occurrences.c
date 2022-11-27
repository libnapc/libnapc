#include <module/parser/_private/_parser.h>

libnapc_size PV_libnapc_parser_countOccurrences(
	const char *string,
	char ch
) {
	libnapc_size num = 0;

	for (libnapc_size i = 0, len = libnapc_strlen(string); i < len; ++i) {
		if (string[i] == ch) ++num;
	}

	return num;
}
