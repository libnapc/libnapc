#include <module/parser/_private/_parser.h>

bool napc_parser_parseBoolean(
	const char *string,
	bool *out
) {
	napc_size length = libnapc_strlen(string);

	if (!length) return false;

	bool value = false;

	if (libnapc_streqli("yes", string)) {
		value = true;
	} else if (libnapc_streqli("true", string)) {
		value = true;
	} else if (libnapc_streqli("1", string)) {
		value = true;
	} else if (libnapc_streqli("no", string)) {
	} else if (libnapc_streqli("false", string)) {
	} else if (libnapc_streqli("0", string)) {
	} else {
		return false;
	}

	if (out) {
		*out = value;
	}

	return true;
}
