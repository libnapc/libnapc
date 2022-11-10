#include <module/ring-buffer/_private/_ring-buffer.h>

void PV_napc_RingBuffer_performAccessFailureAction(
	const napc__RingBuffer *ctx, int performed_action
) {
	// do nothing
	if (ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_NONE) {
		return;
	}

	bool do_panic = ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_PANIC;

	switch (performed_action) {
		case PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTE: {
			if (do_panic) {
				NAPC_PANIC(
					"Read operation failed (READ_BYTE) and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to read byte from empty buffer. " PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;

		case PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTES: {
			if (do_panic) {
				NAPC_PANIC(
					"Read operation failed (READ_BYTES) and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to read bytes from buffer, not enough bytes readable in buffer." PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;

		case PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTE: {
			if (do_panic) {
				NAPC_PANIC(
					"Insert operation (WRITE_BYTE) failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to insert byte into full buffer. " PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;

		case PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTES: {
			if (do_panic) {
				NAPC_PANIC(
					"Insert operation (WRITE_BYTE) failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to place bytes into buffer, not enough free space. " PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;
	}
}
