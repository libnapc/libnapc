#include <module/hr-timer/_private/_hr-timer.h>

void libnapc_HRTimer_restart(libnapc__HRTimer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__HRTimer, timer);

	libnapc_HRTimer_start(timer);
}
