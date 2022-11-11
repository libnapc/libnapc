#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_discardBytes(napc__RingBuffer *ctx, napc_size amount) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	napc_size elements_available = napc_RingBuffer_getAvailableBytes(ctx);

	if (amount > elements_available) {
		amount = elements_available;
	}

	for (napc_size i = 0; i < amount; ++i) {
		napc_RingBuffer_removeByte(ctx, NULL);
	}
}
