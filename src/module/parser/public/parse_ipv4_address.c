#include <module/parser/_private/_parser.h>

bool napc_parser_parseIPv4Address(
	const char *string,
	napc_u8 *out
) {
	// Check occurrences of .
	if (PV_napc_parser_countOccurrences(string, '.') != 3) {
		return false;
	}

	// Max-length of a valid IPv4-Address is 15:
	// libnapc_strlen("255.255.255.255") == 15
	if (libnapc_strlen(string) > 32) return false;

	char copy[32];
	libnapc_strncpy(copy, string, sizeof(copy));

	char *saveptr;
	char *octet = strtok_r(copy, ".", &saveptr);
	int i = 0;

	while (octet) {
		// Octet is too long (max. 3 characters)
		if (libnapc_strlen(octet) > 3) {
			return false;
		}

		// Parse octet
		napc_u32 value;

		if (!PV_napc_parser_parseIntegerString(octet, &value, false)) {
			return false;
		}

		// Out of range
		if (value > 255) return false;

		if (out) {
			out[i] = value;
			++i;
		}

		octet = strtok_r(NULL, ".", &saveptr);
	}

	return true;
}
