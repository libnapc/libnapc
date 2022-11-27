#include <module/ring-buffer/_private/_ring-buffer.h>

void libnapc_RingBuffer_discardByte(libnapc__RingBuffer *ctx) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size n_free_spots = PV_libnapc_RingBuffer_numFreeSpots(ctx);

	// nothing to discard
	if (n_free_spots == ctx->buffer_size) {
		return;
	}

	libnapc_RingBuffer_removeByte(ctx, NULL);
}
