#include <module/timer/_private/_timer.h>

void libnapc_Timer_init(libnapc__Timer *timer, libnapc_time duration, libnapc__TimerMode mode) {
	// validate mode parameter
	if (mode != LIBNAPC_TIMER_MODE_REGULAR && mode != LIBNAPC_TIMER_MODE_ONESHOT) {
		LIBNAPC_PANIC("Invalid value for Timer mode '%u'.", mode);
	}

	timer->mode = mode;
	timer->duration = duration;
	timer->started_at = 0;
	timer->expired = false;
	LIBNAPC_MAGIC_INIT(napc__Timer, timer);
}
