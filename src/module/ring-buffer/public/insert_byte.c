#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_insertByte(napc__RingBuffer *ctx, napc_u8 byte) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	bool result = PV_napc_RingBuffer_insertByte(ctx, byte, false);

	if (!result) {
		PV_napc_RingBuffer_performAccessFailureAction(ctx, 1);
	}

	return result;
}
