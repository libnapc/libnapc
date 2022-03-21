#include <module/misc/_private/_misc.h>

bool napc_misc_verifyMemoryFenceBytes(
	unsigned char *buffer, napc_size buffer_size,
	napc_size memory_fence_size, napc_u8 fence_value
) {
	for (napc_size i = 0; i < memory_fence_size; ++i) {
		napc_u8 actual = buffer[i];

		if (actual != fence_value) {
			return false;
		}

		actual = buffer[buffer_size - 1 - i];

		if (actual != fence_value) {
			return false;
		}
	}

	return true;
}
