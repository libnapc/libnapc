#if !defined(PV_NAPC_MODULE_MEM_h)
	#define PV_NAPC_MODULE_MEM_h

	#include <module/mem/mem.h>
	#include <napc-utils/napc-utils.h>
	#include <napc-core/napc-core.h>

	typedef struct {
		const char *label;
		bool available;
		napc__Buffer buffer;
	} PV_napc__MemSharedBuffer;

	void PV_napc_mem_initSharedBufferSlots(void);

	napc_size PV_napc_mem_countSharedBufferSlots(void);

	PV_napc__MemSharedBuffer *PV_napc_mem_getSharedBufferByLabel(
		const char *label
	);

	extern PV_napc__MemSharedBuffer PV_napc_mem_shared_buffer_slots[5]; // @global
#endif
