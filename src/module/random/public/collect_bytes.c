#include <module/random/_private/_random.h>

void napc_random_collectBytes(void) {
	napc_u8 random_byte;

	if (!napc_getRandomByte(&random_byte)) {
		return;
	}

	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_random_bytes_pool); ++i) {
		if (PV_napc_random_getByteUsed(i)) {
			PV_napc_random_bytes_pool[i] = random_byte;

			PV_napc_random_setByteUsed(i, false);

			break;
		}
	}
}
