#include <module/hr-timer/_private/_hr-timer.h>

void napc_HRTimer_init(napc__HRTimer *timer, napc_time duration, napc__HRTimerMode mode) {
	// validate mode parameter
	if (mode != NAPC_HRTIMER_MODE_REGULAR && mode != NAPC_HRTIMER_MODE_ONESHOT) {
		NAPC_PANIC("Invalid value for Timer mode '%u'.", mode);
	}

	timer->mode = mode;
	timer->duration = duration;
	timer->started_at = 0;
	timer->expired = false;
	NAPC_MAGIC_INIT(napc__HRTimer, timer);
}
