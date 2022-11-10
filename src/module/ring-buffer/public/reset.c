#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_reset(napc__RingBuffer *ctx) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	ctx->write_position = 0;
	ctx->read_position = 0;
	ctx->buffer_full = false;
}
