#include <napc-time/_private/_napc_time.h>

napc_time libnapc_getTimeSinceBootHR(void) {
	return HAL_libnapc_getTimeSinceBoot(true);
}
