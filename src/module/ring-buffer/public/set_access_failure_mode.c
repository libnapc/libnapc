#include <module/ring-buffer/_private/_ring-buffer.h>

void libnapc_RingBuffer_setAccessFailureMode(
	libnapc__RingBuffer *ctx, libnapc__AccessFailureMode mode
) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	if (LIBNAPC_UNLIKELY(!PV_libnapc_validateAccessFailureMode(mode))) {
		LIBNAPC_PANIC("Unrecognized AccessFailureMode '%d'", mode);
	}

	ctx->_fail_mode = mode;
}
