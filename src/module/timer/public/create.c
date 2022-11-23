#include <module/timer/_private/_timer.h>

napc__Timer napc_Timer_create(libnapc_time duration, napc__TimerMode mode) {
	napc__Timer timer;

	napc_Timer_init(&timer, duration, mode);

	return timer;
}
