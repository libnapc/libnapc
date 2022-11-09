#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_forceInsertByte(napc__RingBuffer *ctx, napc_u8 byte) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	NAPC_IGNORE_VALUE(byte);
}
