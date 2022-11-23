#include <module/ring-buffer/_private/_ring-buffer.h>

libnapc_size PV_napc_RingBuffer_numFreeSpots(
	const napc__RingBuffer *ctx
) {
	libnapc_size read_position = ctx->read_position;
	libnapc_size write_position = ctx->write_position;

	if (write_position > read_position) {
		return ctx->buffer_size - (write_position - read_position);
	}

	if (read_position > write_position) {
		return (read_position - write_position);
	}

	// last case is read_position=write_position
	return ctx->buffer_full ? 0 : ctx->buffer_size;
}
