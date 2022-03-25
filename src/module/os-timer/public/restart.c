#include <module/os-timer/_private/_os-timer.h>

void napc_OSTimer_restart(napc__OSTimer *timer) {
	NAPC_MAGIC_ASSERT(napc__OSTimer, timer);

	napc_OSTimer_start(timer);
}
