#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <libnapc-serial/_private/_libnapc-serial.h>
	#include <stdio.h> // fprintf(), stderr

	void HAL_libnapc_putc(char ch) {
		fprintf(stderr, "%c", ch);
	}
#endif
