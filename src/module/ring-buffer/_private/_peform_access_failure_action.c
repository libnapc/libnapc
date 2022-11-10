#include <module/ring-buffer/_private/_ring-buffer.h>

void PV_napc_RingBuffer_performAccessFailureAction(
	const napc__RingBuffer *ctx, int cause
) {
	if (cause == PV_NAPC_MODULE_RINGBUFFER_ACTION_READ) {

		if (ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_LOG) {
			PV_NAPC_RINGBUFFER_ERROR(
				"Refusing to read byte from empty buffer"
				" (write_position=%" NAPC_SIZE_PRINTF ",read_position=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")",
				ctx->write_position,
				ctx->read_position,
				ctx->buffer_size
			);
		} else if (NAPC_UNLIKELY(ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_PANIC)) {
			NAPC_PANIC(
				"Read operation failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
			);
		}

	} else if (cause == PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE) {

		if (ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_LOG) {
			PV_NAPC_RINGBUFFER_ERROR(
				"Refusing to insert byte into full buffer"
				" (write_position=%" NAPC_SIZE_PRINTF ",read_position=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")",
				ctx->write_position,
				ctx->read_position,
				ctx->buffer_size
			);
		} else if (NAPC_UNLIKELY(ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_PANIC)) {
			NAPC_PANIC(
				"Insert operation failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
			);
		}

	}
}
