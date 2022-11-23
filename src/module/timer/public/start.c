#include <module/timer/_private/_timer.h>

void napc_Timer_start(napc__Timer *timer) {
	NAPC_MAGIC_ASSERT(napc__Timer, timer);
	timer->started_at = libnapc_getTimeSinceBoot();
	timer->expired = false;
}
