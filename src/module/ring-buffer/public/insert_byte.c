#include <module/ring-buffer/_private/_ring-buffer.h>

bool libnapc_RingBuffer_insertByte(napc__RingBuffer *ctx, libnapc_u8 byte) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	bool result = PV_libnapc_RingBuffer_insertByte(ctx, byte, false);

	if (!result) {
		PV_libnapc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTE
		);
	}

	return result;
}
