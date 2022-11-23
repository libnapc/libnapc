#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_removeBytes(napc__RingBuffer *ctx, napc_u8 *out, libnapc_size out_size) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size elements_available = napc_RingBuffer_getAvailableBytes(ctx);

	if (out_size > elements_available) {
		PV_napc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTES
		);

		return false;
	}

	for (libnapc_size i = 0; i < out_size; ++i) {
		// allow 'out' to be NULL, this discards the bytes
		napc_u8 *ptr = out ? &out[i] : NULL;

		// this will never be true, hopefully
		if (NAPC_UNLIKELY(!napc_RingBuffer_removeByte(ctx, ptr))) {
			return false;
		}
	}

	return true;
}
