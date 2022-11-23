#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <napc-serial/_private/_napc-serial.h>
	#include <stdio.h> // fprintf(), stderr

	void HAL_libnapc_puts(const char *str) {
		fprintf(stderr, "%s", str);
	}
#endif
