#include <module/misc/_private/_misc.h>

void napc_misc_printHexArray(const void *bytes, napc_size n_bytes) {
	const unsigned char *data = bytes;

	for (napc_size i = 0; i < n_bytes; ++i) {
		libnapc_printf("%2.2x", data[i]);
	}
}
