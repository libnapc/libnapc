#include <module/hr-timer/_private/_hr-timer.h>

bool libnapc_HRTimer_expired(libnapc__HRTimer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__HRTimer, timer);

	if (timer->mode == LIBNAPC_HRTIMER_MODE_REGULAR) {
		if (timer->expired) return true;
	} else if (timer->mode == LIBNAPC_HRTIMER_MODE_ONESHOT) {
		if (timer->expired) return false;
	}

	timer->expired = (libnapc_getTimeSinceBootHR() - timer->started_at) >= timer->duration;

	return timer->expired;
}
