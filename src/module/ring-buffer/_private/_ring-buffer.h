#if !defined(PV_NAPC_MODULE_RINGBUFFER_h)
	#define PV_NAPC_MODULE_RINGBUFFER_h

	#include <module/ring-buffer/ring-buffer.h>
	#include <module/ring-buffer/_private/_log.h>

	#define PV_NAPC_MODULE_RINGBUFFER_ACTION_READ 0
	#define PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE 1

	napc_size PV_napc_RingBuffer_numFreeSpots(
		const napc__RingBuffer *ctx
	);

	bool PV_napc_RingBuffer_insertByte(
		napc__RingBuffer *ctx, napc_u8 byte, bool force
	);

	void PV_napc_RingBuffer_performAccessFailureAction(
		const napc__RingBuffer *ctx, int cause
	);
#endif
