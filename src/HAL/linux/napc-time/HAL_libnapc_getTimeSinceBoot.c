#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <napc-time/_private/_napc_time.h>
	#include <time.h> // struct timespec, clock_gettime()

	extern struct timespec PV_napc_program_start_linux; // @global

	libnapc_time HAL_libnapc_getTimeSinceBoot(bool high_res) {
		struct timespec now;

		clock_gettime(CLOCK_MONOTONIC_RAW, &now);

		long delta_seconds = (now.tv_sec - PV_napc_program_start_linux.tv_sec);
		long delta_nseconds = (now.tv_nsec - PV_napc_program_start_linux.tv_nsec);

		long delta = 0;

		if (high_res) {
			delta += (delta_seconds * 1000000); // 1sec = 1000000us
			delta += (delta_nseconds / 1000); // 1000ns = 1us

			return (libnapc_time)delta;
		}

		delta += (delta_seconds * 1000); // 1sec = 1000ms
		delta += (delta_nseconds / 1000000); // 1000000ns = 1ms

		return (libnapc_time)delta;
	}
#endif
