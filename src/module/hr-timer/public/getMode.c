#include <module/hr-timer/_private/_hr-timer.h>

napc__HRTimerMode napc_HRTimer_getMode(const napc__HRTimer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__HRTimer, timer);

	return timer->mode;
}
