#include <module/timer/_private/_timer.h>

void libnapc_Timer_start(libnapc__Timer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__Timer, timer);
	timer->started_at = libnapc_getTimeSinceBoot();
	timer->expired = false;
}
