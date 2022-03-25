#include <module/os-timer/_private/_os-timer.h>

void napc_OSTimer_start(napc__OSTimer *timer) {
	NAPC_MAGIC_ASSERT(napc__OSTimer, timer);
	timer->started_at = napc_getTimeSinceBoot();
	timer->expired = false;
}
