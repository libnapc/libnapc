#include <module/timer/_private/_timer.h>

void napc_Timer_init(napc__Timer *timer, napc_time duration) {
	timer->duration = duration;
	timer->started_at = 0;
	timer->expired = false;
	NAPC_MAGIC_INIT(napc__Timer, timer);
}
