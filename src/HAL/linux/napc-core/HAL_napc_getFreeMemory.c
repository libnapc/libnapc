#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <napc-core/_private/_napc-core.h>

	napc_size HAL_napc_getFreeMemory(void) {
		return 0;
	}
#endif
