#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_forceInsertByte(napc__RingBuffer *ctx, libnapc_u8 byte) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	LIBNAPC_IGNORE_VALUE(
		PV_napc_RingBuffer_insertByte(ctx, byte, true)
	);
}
