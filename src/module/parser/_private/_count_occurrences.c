#include <module/parser/_private/_parser.h>

napc_size PV_napc_parser_countOccurrences(
	const char *string,
	char ch
) {
	napc_size num = 0;

	for (napc_size i = 0, len = napc_strlen(string); i < len; ++i) {
		if (string[i] == ch) ++num;
	}

	return num;
}
