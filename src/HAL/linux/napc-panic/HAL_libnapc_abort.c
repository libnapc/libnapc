#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <libnapc-panic/_private/_libnapc-panic.h>
	#include <stdlib.h> // exit(), EXIT_FAILURE

	void HAL_libnapc_abort(void) {
		exit(EXIT_FAILURE);
	}
#endif
