#include <napc-time/_private/_napc_time.h>

libnapc_time libnapc_getTimeSinceBoot(void) {
	return HAL_libnapc_getTimeSinceBoot(false);
}
