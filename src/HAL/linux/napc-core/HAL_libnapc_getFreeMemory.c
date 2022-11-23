#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <napc-core/_private/_napc-core.h>

	libnapc_size HAL_libnapc_getFreeMemory(void) {
		return 0;
	}
#endif
