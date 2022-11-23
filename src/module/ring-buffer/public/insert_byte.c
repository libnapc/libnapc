#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_insertByte(napc__RingBuffer *ctx, libnapc_u8 byte) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	bool result = PV_napc_RingBuffer_insertByte(ctx, byte, false);

	if (!result) {
		PV_napc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTE
		);
	}

	return result;
}
