#include <module/mem/_private/_mem.h>

void napc_mem_releaseSharedBuffer(
	napc__Buffer *buffer
) {
	PV_napc__MemSharedBuffer *target = NULL;

	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_mem_shared_buffer_slots); ++i) {
		PV_napc__MemSharedBuffer *e = &PV_napc_mem_shared_buffer_slots[i];

		// ignore uninitialized entries
		if (!e->label) continue;
		if (&e->buffer != buffer) continue;

		target = e;
	}

	if (!target) {
		NAPC_PANIC(
			"Invalid buffer passed to napc_mem_releaseSharedBuffer()."
		);
	} else if (target->available) {
		NAPC_PANIC(
			"Cannot release an unclaimed shared buffer."
		);
	}

	target->available = true;
}
