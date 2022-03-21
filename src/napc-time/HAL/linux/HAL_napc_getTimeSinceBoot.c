#if !defined(ARDUINO)
	#include <napc-time/_private/_napc_time.h>
	#include <time.h> // struct timespec, clock_gettime()

	extern struct timespec PV_napc_program_start_linux; // @global

	napc_time HAL_napc_getTimeSinceBoot(void) {
		struct timespec now;

		clock_gettime(CLOCK_MONOTONIC_RAW, &now);

		long delta_seconds = (now.tv_sec - PV_napc_program_start_linux.tv_sec);
		long delta_nseconds = (now.tv_nsec - PV_napc_program_start_linux.tv_nsec);

		long delta = 0;

		delta += (delta_seconds * 1000); // 1sec = 1000ms
		delta += (delta_nseconds / 1000000); // 1000000ns = 1ms

		return (napc_time)delta;
	}
#endif
