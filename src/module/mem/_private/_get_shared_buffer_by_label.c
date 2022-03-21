#include <module/mem/_private/_mem.h>

PV_napc__MemSharedBuffer *PV_napc_mem_getSharedBufferByLabel(
	const char *label
) {
	// check for name duplicates
	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_mem_shared_buffer_slots); ++i) {
		PV_napc__MemSharedBuffer *e = &PV_napc_mem_shared_buffer_slots[i];

		// ignore uninitialized entries
		if (!e->label) continue;

		if (napc_streqli(e->label, label)) {
			return e;
		}
	}

	return NULL;
}
