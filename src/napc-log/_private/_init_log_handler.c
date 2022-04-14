#include <napc-log/_private/_napc-log.h>

void PV_napc_initLogHandler(void) {
	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_log_handler_array); ++i) {
		PV_napc_log_handler_array[i] = NULL;
	}
}
