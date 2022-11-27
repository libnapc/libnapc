#include <module/ring-buffer/_private/_ring-buffer.h>

libnapc_size libnapc_RingBuffer_getAvailableBytes(const napc__RingBuffer *ctx) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	return ctx->buffer_size - PV_libnapc_RingBuffer_numFreeSpots(ctx);
}
