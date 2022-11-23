#include <module/parser/_private/_parser.h>

bool napc_parser_parseDecimalNumberU16(
	const char *string,
	napc_u16 *out
) {
	libnapc_u32 tmp;

	if (!PV_napc_parser_parseIntegerString(string, &tmp, false)) return false;

	if (out) {
		*out = (napc_u16)(tmp & 0xFFFFu);
	}

	return true;
}
