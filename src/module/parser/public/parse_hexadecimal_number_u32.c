#include <module/parser/_private/_parser.h>

bool libnapc_parser_parseHexadecimalNumberU32(
	const char *string,
	libnapc_u32 *out
) {
	return PV_libnapc_parser_parseIntegerString(string, out, true);
}
