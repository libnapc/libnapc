#include <module/ring-buffer/_private/_ring-buffer.h>

bool libnapc_RingBuffer_insertBytes(libnapc__RingBuffer *ctx, const libnapc_u8 *bytes, libnapc_size bytes_size) {
	LIBNAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	libnapc_size free_spots = PV_libnapc_RingBuffer_numFreeSpots(ctx);

	if (bytes_size > free_spots) {
		PV_libnapc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_LIBNAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTES
		);

		return false;
	}

	for (libnapc_size i = 0; i < bytes_size; ++i) {
		// this will never be true, hopefully
		if (LIBNAPC_UNLIKELY(!libnapc_RingBuffer_insertByte(ctx, bytes[i]))) {
			return false;
		}
	}

	return true;
}
