#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_removeByte(napc__RingBuffer *ctx, napc_u8 *out) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	NAPC_IGNORE_VALUE(out);

	return false;
}
