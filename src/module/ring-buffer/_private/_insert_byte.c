#include <module/ring-buffer/_private/_ring-buffer.h>

bool PV_libnapc_RingBuffer_insertByte(
	libnapc__RingBuffer *ctx, libnapc_u8 byte, bool force
) {
	libnapc_size n_free_spots = PV_libnapc_RingBuffer_numFreeSpots(ctx);

	if (!force) {
		// no space available
		if (n_free_spots == 0) {
			return false;
		}

		// buffer will be full if only one element is free
		ctx->buffer_full = (n_free_spots == 1);
	} else {
		// buffer will be full if only one element is free, or no elements are available
		ctx->buffer_full = (n_free_spots == 1 || n_free_spots == 0);
	}

	libnapc_size new_write_position = (ctx->write_position + 1) % ctx->buffer_size;

	ctx->buffer[ctx->write_position] = byte;

	ctx->write_position = new_write_position;

	return true;
}
