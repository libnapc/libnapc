#include <module/hr-timer/_private/_hr-timer.h>

void napc_HRTimer_start(napc__HRTimer *timer) {
	NAPC_MAGIC_ASSERT(napc__HRTimer, timer);
	timer->started_at = napc_getTimeSinceBootHR();
	timer->expired = false;
}
