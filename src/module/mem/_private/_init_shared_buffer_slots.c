#include <module/mem/_private/_mem.h>

void PV_napc_mem_initSharedBufferSlots(void) {
	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_mem_shared_buffer_slots); ++i) {
		PV_napc__MemSharedBuffer *e = &PV_napc_mem_shared_buffer_slots[i];

		e->label = NULL;
		e->available = false;
	}
}
