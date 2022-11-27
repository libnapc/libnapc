#include <module/timer/_private/_timer.h>

libnapc__TimerMode libnapc_Timer_getMode(const libnapc__Timer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__Timer, timer);

	return timer->mode;
}
