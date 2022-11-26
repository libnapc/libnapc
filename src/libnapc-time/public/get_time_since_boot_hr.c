#include <libnapc-time/_private/_libnapc_time.h>

libnapc_time libnapc_getTimeSinceBootHR(void) {
	return HAL_libnapc_getTimeSinceBoot(true);
}
