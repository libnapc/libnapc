#include <module/ring-buffer/_private/_ring-buffer.h>

napc_size napc_RingBuffer_getBufferSize(const napc__RingBuffer *ctx) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	return ctx->buffer_size;
}
