#include <module/misc/_private/_misc.h>

void libnapc_misc_printHexArray(const void *bytes, libnapc_size n_bytes) {
	const unsigned char *data = bytes;

	for (libnapc_size i = 0; i < n_bytes; ++i) {
		libnapc_printf("%2.2x", data[i]);
	}
}
