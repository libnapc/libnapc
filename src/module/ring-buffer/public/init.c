#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_init(
	napc__RingBuffer *ctx, napc_u8 *buffer, napc_size buffer_size
) {
	if (!buffer_size) {
		LIBNAPC_PANIC("Size cannot be zero inside napc_RingBuffer_init().");
	}

	ctx->_fail_mode = PV_napc_getDefaultAccessFailureMode();

	ctx->buffer = buffer;
	ctx->buffer_size = buffer_size;

	ctx->read_position = 0;
	ctx->write_position = 0;

	ctx->buffer_full = false;

	NAPC_MAGIC_INIT(napc__RingBuffer, ctx);
}
