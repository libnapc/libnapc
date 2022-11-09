#if !defined(PV_NAPC_MODULE_RINGBUFFER_h)
	#define PV_NAPC_MODULE_RINGBUFFER_h

	#include <module/ring-buffer/ring-buffer.h>
	#include <module/ring-buffer/_private/_log.h>

	napc_size PV_napc_RingBuffer_numFreeSpots(
		const napc__RingBuffer *ctx
	);

	bool PV_napc_RingBuffer_insertByte(
		napc__RingBuffer *ctx, napc_u8 byte, bool force
	);
#endif
