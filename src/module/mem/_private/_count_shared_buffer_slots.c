#include <module/mem/_private/_mem.h>

napc_size PV_napc_mem_countSharedBufferSlots(void) {
	napc_size num = 0;

	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_mem_shared_buffer_slots); ++i) {
		if (PV_napc_mem_shared_buffer_slots[i].label) {
			++num;
		}
	}

	return num;
}
