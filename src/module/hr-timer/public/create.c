#include <module/hr-timer/_private/_hr-timer.h>

napc__HRTimer napc_HRTimer_create(napc_time duration, napc__HRTimerMode mode) {
	napc__HRTimer timer;

	napc_HRTimer_init(&timer, duration, mode);

	return timer;
}
