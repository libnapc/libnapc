#include <napc-time/_private/_napc_time.h>

napc_time napc_getTimeSinceBoot(void) {
	return HAL_napc_getTimeSinceBoot(false);
}
