#include <module/ring-buffer/_private/_ring-buffer.h>

void napc_RingBuffer_discardBytes(napc__RingBuffer *ctx, libnapc_size amount) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size elements_available = napc_RingBuffer_getAvailableBytes(ctx);

	if (amount > elements_available) {
		amount = elements_available;
	}

	napc_RingBuffer_removeBytes(ctx, NULL, amount);
}
