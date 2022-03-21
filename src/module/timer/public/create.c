#include <module/timer/_private/_timer.h>

napc__Timer napc_Timer_create(napc_time duration) {
	napc__Timer timer;

	napc_Timer_init(&timer, duration);

	return timer;
}
