#include <module/ring-buffer/_private/_ring-buffer.h>

void libnapc_RingBuffer_reset(libnapc__RingBuffer *ctx) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	ctx->write_position = 0;
	ctx->read_position = 0;
	ctx->buffer_full = false;
}
