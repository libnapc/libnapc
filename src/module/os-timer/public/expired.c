#include <module/os-timer/_private/_os-timer.h>

bool napc_OSTimer_expired(napc__OSTimer *timer) {
	NAPC_MAGIC_ASSERT(napc__OSTimer, timer);
	if (timer->expired) return false;

	timer->expired = (napc_getTimeSinceBoot() - timer->started_at) >= timer->duration;

	return timer->expired;
}
