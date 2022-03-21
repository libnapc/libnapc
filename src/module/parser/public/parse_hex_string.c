#include <module/parser/_private/_parser.h>

bool napc_parser_parseHexString(
	const char *string,
	napc_size n_bytes,
	napc_u8 *out
) {
	if (napc_strlen(string) != (n_bytes * 2)) {
		return false;
	}

	napc_size out_index = 0;

	for (napc_size i = 0; i < n_bytes; ++i) {
		char tmp_str[3] = {0,0,0};

		napc_size first_index = i * 2;
		napc_size second_index = first_index + 1;

		tmp_str[0] = string[first_index];
		tmp_str[1] = string[second_index];

		napc_u8 value = 0;

		bool result = napc_parser_parseHexadecimalNumberU8(tmp_str, &value);

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
