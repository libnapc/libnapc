#include <napc-core/_private/_napc-core.h>

napc_size napc_getFreeMemory(void) {
	return HAL_napc_getFreeMemory();
}
