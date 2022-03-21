#include <napc-utils/_private/_napc-utils.h>

void napc_strncpy(char *dest, const char *source, napc_size dest_size) {
	strncpy(dest, source, dest_size);

	// always termiante dest (strncpy doesn't do that)
	dest[dest_size - 1] = 0;
}
