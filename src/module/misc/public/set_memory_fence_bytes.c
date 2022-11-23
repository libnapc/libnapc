#include <module/misc/_private/_misc.h>

void napc_misc_setMemoryFenceBytes(
	unsigned char *buffer, libnapc_size buffer_size,
	libnapc_size memory_fence_size, napc_u8 fence_value
) {
	for (libnapc_size i = 0; i < memory_fence_size; ++i) {
		buffer[i] = fence_value;
		buffer[buffer_size - 1 - i] = fence_value;
	}
}
