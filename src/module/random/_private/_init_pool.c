#include <module/random/_private/_random.h>

void PV_napc_random_initPool(void) {
	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_used_random_bytes); ++i) {
		// mark all bytes as used
		PV_napc_used_random_bytes[i] = 0xFF;
	}

	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_random_bytes_pool); ++i) {
		PV_napc_random_bytes_pool[i] = 0;
	}
}
