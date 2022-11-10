#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_removeByte(napc__RingBuffer *ctx, napc_u8 *out) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	napc_size n_free_spots = PV_napc_RingBuffer_numFreeSpots(ctx);

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

	napc_size new_read_position = (ctx->read_position + 1) % ctx->buffer_size;

	ctx->read_position = new_read_position;

	// buffer will not be full again after a read operation
	ctx->buffer_full = false;

	return true;
}
