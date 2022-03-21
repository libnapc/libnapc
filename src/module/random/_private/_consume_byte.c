#include <module/random/_private/_random.h>
#include <napc-core/napc-core.h> // NAPC_ASSERT()

napc_u8 PV_napc_random_consumeByte(void) {
	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_random_bytes_pool); ++i) {
		if (!PV_napc_random_getByteUsed(i)) {
			napc_u8 byte = PV_napc_random_bytes_pool[i];

			PV_napc_random_setByteUsed(i, true);

			return byte;
		}
	}

	NAPC_ASSERT(false);
	return 0x00;
}
