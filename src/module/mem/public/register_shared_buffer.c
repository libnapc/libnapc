#include <module/mem/_private/_mem.h>

void napc_mem_registerSharedBuffer(
	const char *label, void *buffer, napc_size buffer_size
) {
	napc_size max_slots       = NAPC_ARRAY_ELEMENTS(PV_napc_mem_shared_buffer_slots);
	napc_size available_slots = max_slots - PV_napc_mem_countSharedBufferSlots();

	if (!available_slots) {
		NAPC_PANIC(
			"Cannot register another shared buffer, slots are full."
			" Maximum is %" NAPC_SIZE_PRINTF,
			max_slots
		);
	}

	// check for name duplicates
	if (PV_napc_mem_getSharedBufferByLabel(label)) {
		NAPC_PANIC(
			"There is already a shared buffer with the label '%s'.",
			label
		);
	}

	bool inserted = false;

	for (napc_size i = 0; i < max_slots; ++i) {
		PV_napc__MemSharedBuffer *e = &PV_napc_mem_shared_buffer_slots[i];

		// Initialize first uninitialized entry
		if (!e->label) {
			e->label = label;
			napc_Buffer_init(&e->buffer, buffer, buffer_size);
			e->available = true;

			inserted = true;

			break;
		}
	}

	NAPC_ASSERT(inserted);
}
