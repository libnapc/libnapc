#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_peekByte(const napc__RingBuffer *ctx, napc_u8 *out) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size n_free_spots = PV_napc_RingBuffer_numFreeSpots(ctx);

	if (n_free_spots == ctx->buffer_size) {
		PV_napc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTE
		);

		return false;
	}

	if (out) {
		*out = ctx->buffer[ctx->read_position];
	}

	return true;
}
