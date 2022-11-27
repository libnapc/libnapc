#include <module/parser/_private/_parser.h>

bool napc_parser_parseHexString(
	const char *string,
	libnapc_size n_bytes,
	libnapc_u8 *out
) {
	if (libnapc_strlen(string) != (n_bytes * 2)) {
		return false;
	}

	libnapc_size out_index = 0;

	for (libnapc_size i = 0; i < n_bytes; ++i) {
		char tmp_str[3] = {0,0,0};

		libnapc_size first_index = i * 2;
		libnapc_size second_index = first_index + 1;

		tmp_str[0] = string[first_index];
		tmp_str[1] = string[second_index];

		libnapc_u8 value = 0;

		bool result = libnapc_parser_parseHexadecimalNumberU8(tmp_str, &value);

		// wipe memory
		tmp_str[0] = 0;
		tmp_str[1] = 0;

		if (!result) return false;

		if (out) {
			out[out_index] = value;
			++out_index;
			// wipe memory
			value = 0;
		}
	}

	return true;
}
