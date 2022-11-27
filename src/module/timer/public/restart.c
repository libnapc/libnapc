#include <module/timer/_private/_timer.h>

void libnapc_Timer_restart(libnapc__Timer *timer) {
	LIBNAPC_MAGIC_ASSERT(napc__Timer, timer);

	libnapc_Timer_start(timer);
}
