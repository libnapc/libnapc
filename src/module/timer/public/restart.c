#include <module/timer/_private/_timer.h>

void napc_Timer_restart(napc__Timer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__Timer, timer);

	napc_Timer_start(timer);
}
