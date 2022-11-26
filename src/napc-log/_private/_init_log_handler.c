#include <napc-log/_private/_napc-log.h>

void PV_libnapc_initLogHandler(void) {
	for (libnapc_size i = 0; i < LIBNAPC_ARRAY_ELEMENTS(PV_libnapc_log_handler_array); ++i) {
		PV_libnapc_log_handler_array[i] = NULL;
	}
}
