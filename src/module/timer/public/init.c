#include <module/timer/_private/_timer.h>

void napc_Timer_init(napc__Timer *timer, napc_time duration, napc__TimerMode mode) {
	// validate mode parameter
	if (mode != NAPC_TIMER_MODE_REGULAR && mode != NAPC_TIMER_MODE_ONESHOT) {
		NAPC_PANIC("Invalid value for Timer mode '%u'.", mode);
	}

	timer->mode = mode;
	timer->duration = duration;
	timer->started_at = 0;
	timer->expired = false;
	NAPC_MAGIC_INIT(napc__Timer, timer);
}
