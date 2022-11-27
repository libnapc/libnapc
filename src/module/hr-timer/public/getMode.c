#include <module/hr-timer/_private/_hr-timer.h>

libnapc__HRTimerMode libnapc_HRTimer_getMode(const libnapc__HRTimer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__HRTimer, timer);

	return timer->mode;
}
