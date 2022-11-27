#include <module/timer/_private/_timer.h>

libnapc__Timer libnapc_Timer_create(libnapc_time duration, libnapc__TimerMode mode) {
	libnapc__Timer timer;

	libnapc_Timer_init(&timer, duration, mode);

	return timer;
}
