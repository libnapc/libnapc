#include <module/timer/_private/_timer.h>

napc__TimerMode napc_Timer_getMode(const napc__Timer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__Timer, timer);

	return timer->mode;
}
