#include <module/hr-timer/_private/_hr-timer.h>

void napc_HRTimer_start(napc__HRTimer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__HRTimer, timer);
	timer->started_at = libnapc_getTimeSinceBootHR();
	timer->expired = false;
}
