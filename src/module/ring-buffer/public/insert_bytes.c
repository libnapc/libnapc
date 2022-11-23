#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_insertBytes(napc__RingBuffer *ctx, const napc_u8 *bytes, napc_size bytes_size) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	napc_size free_spots = PV_napc_RingBuffer_numFreeSpots(ctx);

	if (bytes_size > free_spots) {
		PV_napc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTES
		);

		return false;
	}

	for (napc_size i = 0; i < bytes_size; ++i) {
		// this will never be true, hopefully
		if (NAPC_UNLIKELY(!napc_RingBuffer_insertByte(ctx, bytes[i]))) {
			return false;
		}
	}

	return true;
}