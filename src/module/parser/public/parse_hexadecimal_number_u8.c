#include <module/parser/_private/_parser.h>

bool napc_parser_parseHexadecimalNumberU8(
	const char *string,
	napc_u8 *out
) {
	napc_u32 tmp;

	if (!PV_napc_parser_parseIntegerString(string, &tmp, true)) {
		return false;
	}

	if (out) {
		*out = (napc_u8)(tmp & 0xFFu);
	}

	return true;
}
