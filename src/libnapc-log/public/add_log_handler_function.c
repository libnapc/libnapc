#include <libnapc-log/_private/_libnapc-log.h>

libnapc_ssize libnapc_addLogHandlerFunction(
	libnapc_logHandlerFunction handler, void *context
) {
	libnapc_ssize next_handler = -1;

	for (libnapc_size i = 0; i < LIBNAPC_ARRAY_ELEMENTS(PV_libnapc_log_handler_array); ++i) {
		if (PV_libnapc_log_handler_array[i] == NULL) {
			next_handler = i;
		}
	}

	if (next_handler == -1) {
		return -1;
	}

	PV_libnapc_log_handler_array[next_handler] = handler;
	PV_libnapc_log_handler_context_array[next_handler] = context;

	return next_handler;
}
