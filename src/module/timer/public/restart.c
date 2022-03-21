#include <module/timer/_private/_timer.h>

void napc_Timer_restart(napc__Timer *timer) {
	NAPC_MAGIC_ASSERT(napc__Timer, timer);
	// if (!timer->expired)
	napc_Timer_start(timer);
}
