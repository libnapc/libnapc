#include <module/ring-buffer/_private/_ring-buffer.h>

bool libnapc_RingBuffer_removeBytes(napc__RingBuffer *ctx, libnapc_u8 *out, libnapc_size out_size) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size elements_available = libnapc_RingBuffer_getAvailableBytes(ctx);

	if (out_size > elements_available) {
		PV_libnapc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_READ_BYTES
		);

		return false;
	}

	for (libnapc_size i = 0; i < out_size; ++i) {
		// allow 'out' to be NULL, this discards the bytes
		libnapc_u8 *ptr = out ? &out[i] : NULL;

		// this will never be true, hopefully
		if (LIBNAPC_UNLIKELY(!libnapc_RingBuffer_removeByte(ctx, ptr))) {
			return false;
		}
	}

	return true;
}
