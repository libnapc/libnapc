#include <module/timer/_private/_timer.h>

bool libnapc_Timer_expired(libnapc__Timer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__Timer, timer);

	if (timer->mode == LIBNAPC_TIMER_MODE_REGULAR) {
		if (timer->expired) return true;
	} else if (timer->mode == LIBNAPC_TIMER_MODE_ONESHOT) {
		if (timer->expired) return false;
	}

	timer->expired = (libnapc_getTimeSinceBoot() - timer->started_at) >= timer->duration;

	return timer->expired;
}
