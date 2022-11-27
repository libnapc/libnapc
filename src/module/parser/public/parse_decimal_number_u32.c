#include <module/parser/_private/_parser.h>

bool libnapc_parser_parseDecimalNumberU32(
	const char *string,
	libnapc_u32 *out
) {
	return PV_napc_parser_parseIntegerString(string, out, false);
}
