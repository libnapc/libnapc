#include <module/mem/_private/_mem.h>

void napc_mem_claimSharedBuffer(
	const char *label, napc__Buffer **out
) {
	PV_napc__MemSharedBuffer *e = PV_napc_mem_getSharedBufferByLabel(label);

	if (!e) {
		NAPC_PANIC(
			"There is no shared buffer with label '%s'.",
			label
		);
	} else if (!e->available) {
		NAPC_PANIC(
			"Shared buffer cannot be claimed as it was already claimed"
			" by some other piece of code."
		);
	}

	e->available = false;
	*out = &e->buffer;
}
