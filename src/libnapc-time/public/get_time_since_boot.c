#include <libnapc-time/_private/_libnapc_time.h>

libnapc_time libnapc_getTimeSinceBoot(void) {
	return HAL_libnapc_getTimeSinceBoot(false);
}
