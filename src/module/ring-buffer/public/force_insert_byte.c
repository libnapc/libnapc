#include <module/ring-buffer/_private/_ring-buffer.h>

void libnapc_RingBuffer_forceInsertByte(napc__RingBuffer *ctx, libnapc_u8 byte) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	LIBNAPC_IGNORE_VALUE(
		PV_libnapc_RingBuffer_insertByte(ctx, byte, true)
	);
}
