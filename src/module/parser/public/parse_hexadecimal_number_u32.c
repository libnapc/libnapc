#include <module/parser/_private/_parser.h>

bool napc_parser_parseHexadecimalNumberU32(
	const char *string,
	napc_u32 *out
) {
	return PV_napc_parser_parseIntegerString(string, out, true);
}
