#include <napc-core/_private/_napc-core.h>

libnapc_size libnapc_getFreeMemory(void) {
	return HAL_libnapc_getFreeMemory();
}
