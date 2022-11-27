#include <module/ring-buffer/_private/_ring-buffer.h>

void libnapc_RingBuffer_discardBytes(napc__RingBuffer *ctx, libnapc_size amount) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size elements_available = libnapc_RingBuffer_getAvailableBytes(ctx);

	if (amount > elements_available) {
		amount = elements_available;
	}

	libnapc_RingBuffer_removeBytes(ctx, NULL, amount);
}
