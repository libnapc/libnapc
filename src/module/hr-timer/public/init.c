#include <module/hr-timer/_private/_hr-timer.h>

void libnapc_HRTimer_init(libnapc__HRTimer *timer, libnapc_time duration, libnapc__HRTimerMode mode) {
	// validate mode parameter
	if (mode != LIBNAPC_HRTIMER_MODE_REGULAR && mode != LIBNAPC_HRTIMER_MODE_ONESHOT) {
		LIBNAPC_PANIC("Invalid value for Timer mode '%u'.", mode);
	}

	timer->mode = mode;
	timer->duration = duration;
	timer->started_at = 0;
	timer->expired = false;
	LIBNAPC_MAGIC_INIT(napc__HRTimer, timer);
}
