#include <module/parser/_private/_parser.h>

bool napc_parser_parseHexadecimalNumberU16(
	const char *string,
	libnapc_u16 *out
) {
	libnapc_u32 tmp;

	if (!PV_napc_parser_parseIntegerString(string, &tmp, true)) {
		return false;
	}

	if (out) {
		*out = (libnapc_u16)(tmp & 0xFFFFu);
	}

	return true;
}
