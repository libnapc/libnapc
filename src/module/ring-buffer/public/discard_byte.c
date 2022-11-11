#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_discardByte(napc__RingBuffer *ctx) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	napc_size n_free_spots = PV_napc_RingBuffer_numFreeSpots(ctx);

	// nothing to discard
	if (n_free_spots == ctx->buffer_size) {
		return;
	}

	napc_RingBuffer_removeByte(ctx, NULL);
}
