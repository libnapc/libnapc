#if !defined(ARDUINO)
	#include <napc-core/_private/_napc-core.h>

	napc_size HAL_napc_getFreeMemory(void) {
		return 0;
	}
#endif
