#include <module/ring-buffer/_private/_ring-buffer.h>

bool libnapc_RingBuffer_peekByte(const libnapc__RingBuffer *ctx, libnapc_u8 *out) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size n_free_spots = PV_libnapc_RingBuffer_numFreeSpots(ctx);

	if (n_free_spots == ctx->buffer_size) {
		PV_libnapc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_READ_BYTE
		);

		return false;
	}

	if (out) {
		*out = ctx->buffer[ctx->read_position];
	}

	return true;
}
