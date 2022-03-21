#include <module/random/_private/_random.h>

bool napc_random_getRandomBytes(napc_size n_bytes, napc_u8 *out) {
	napc_size bytes_available = napc_random_getAvailableBytes();

	if (n_bytes > bytes_available) return false;

	for (napc_size i = 0; i < n_bytes; ++i) {
		out[i] = PV_napc_random_consumeByte();
	}

	return true;
}
