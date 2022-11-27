#include <module/hr-timer/_private/_hr-timer.h>

libnapc__HRTimer libnapc_HRTimer_create(libnapc_time duration, libnapc__HRTimerMode mode) {
	libnapc__HRTimer timer;

	libnapc_HRTimer_init(&timer, duration, mode);

	return timer;
}
