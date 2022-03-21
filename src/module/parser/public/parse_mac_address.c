#include <module/parser/_private/_parser.h>

bool napc_parser_parseMACAddress(
	const char *string,
	napc_u8 *out
) {
	// Check occurrences of :
	if (PV_napc_parser_countOccurrences(string, ':') != 5) {
		return false;
	}

	// Max-length of a valid MAC-Address is 17:
	// napc_strlen("ff:ff:ff:ff:ff:ff") == 17
	if (napc_strlen(string) > 32) return false;

	char copy[32];
	napc_strncpy(copy, string, sizeof(copy));

	char *saveptr;
	char *octet = strtok_r(copy, ":", &saveptr);
	int i = 0;

	while (octet) {
		// Octet is too long (max. 2 characters)
		if (napc_strlen(octet) > 2) {
			return false;
		}

		// Parse octet
		napc_u32 value;

		if (!PV_napc_parser_parseIntegerString(octet, &value, true)) {
			return false;
		}

		if (out) {
			out[i] = value;
			++i;
		}

		octet = strtok_r(NULL, ":", &saveptr);
	}

	return true;
}
