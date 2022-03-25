#include <module/timer/_private/_timer.h>

bool napc_Timer_expired(napc__Timer *timer) {
	NAPC_MAGIC_ASSERT(napc__Timer, timer);
	if (timer->expired) return true;

	timer->expired = (napc_getTimeSinceBoot() - timer->started_at) >= timer->duration;

	return timer->expired;
}
