#include <libnapc-core/_private/_libnapc-core.h>

libnapc_size libnapc_getFreeMemory(void) {
	return HAL_libnapc_getFreeMemory();
}
