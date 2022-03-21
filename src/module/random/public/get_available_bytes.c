#include <module/random/_private/_random.h>

napc_size napc_random_getAvailableBytes(void) {
	napc_size n = 0;

	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_random_bytes_pool); ++i) {
		if (!PV_napc_random_getByteUsed(i)) {
			++n;
		}
	}

	return n;
}
