#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_setAccessFailureMode(
	napc__RingBuffer *ctx, napc__AccessFailureMode mode
) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	if (NAPC_UNLIKELY(!PV_napc_validateAccessFailureMode(mode))) {
		NAPC_PANIC("Unrecognized AccessFailureMode '%d'", mode);
	}

	ctx->_fail_mode = mode;
}
