#include <libnapc-log/_private/_libnapc-log.h>

void libnapc_removeLogHandlerFunction(
	libnapc_size log_handler_index
) {
	LIBNAPC_ASSERT(5 > log_handler_index);

	if (PV_libnapc_log_handler_array[log_handler_index] == NULL) {
		LIBNAPC_PANIC(
			"Trying to remove already removed log handler."
		);
	}

	PV_libnapc_log_handler_array[log_handler_index] = NULL;
}
