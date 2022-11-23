#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <napc-time/_private/_napc_time.h>
	#include <time.h> // struct timespec, clock_gettime()

	struct timespec PV_napc_program_start_linux; // @global

	void HAL_libnapc_initTime(void) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &PV_napc_program_start_linux);
	}
#endif
