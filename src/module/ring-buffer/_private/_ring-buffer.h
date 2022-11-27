#if !defined(PV_LIBNAPC_MODULE_RINGBUFFER_h)
	#define PV_LIBNAPC_MODULE_RINGBUFFER_h

	#include <module/ring-buffer/ring-buffer.h>
	#include <module/ring-buffer/_private/_log.h>

	#define PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_READ_BYTE   0
	#define PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_READ_BYTES  1
	#define PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTE  2
	#define PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTES 3

	#define PV_LIBNAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT \
		"(write_position=%" LIBNAPC_SIZE_PRINT_DEC ",read_position=%" LIBNAPC_SIZE_PRINT_DEC ",size=%" LIBNAPC_SIZE_PRINT_DEC ")"

	#define PV_LIBNAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES \
		ctx->write_position, ctx->read_position, ctx->buffer_size

	libnapc_size PV_libnapc_RingBuffer_numFreeSpots(
		const napc__RingBuffer *ctx
	);

	bool PV_libnapc_RingBuffer_insertByte(
		napc__RingBuffer *ctx, libnapc_u8 byte, bool force
	);

	void PV_libnapc_RingBuffer_performAccessFailureAction(
		const napc__RingBuffer *ctx, int performed_action
	);
#endif
