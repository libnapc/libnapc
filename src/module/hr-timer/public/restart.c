#include <module/hr-timer/_private/_hr-timer.h>

void napc_HRTimer_restart(napc__HRTimer *timer) {
	NAPC_MAGIC_ASSERT(napc__HRTimer, timer);

	napc_HRTimer_start(timer);
}
