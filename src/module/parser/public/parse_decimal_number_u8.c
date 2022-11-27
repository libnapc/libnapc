#include <module/parser/_private/_parser.h>

bool libnapc_parser_parseDecimalNumberU8(
	const char *string,
	libnapc_u8 *out
) {
	libnapc_u32 tmp;

	if (!PV_libnapc_parser_parseIntegerString(string, &tmp, false)) return false;

	if (out) {
		*out = (libnapc_u8)(tmp & 0xFFu);
	}

	return true;
}
