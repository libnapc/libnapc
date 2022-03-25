#include <module/os-timer/_private/_os-timer.h>

void napc_OSTimer_init(napc__OSTimer *timer, napc_time duration) {
	timer->duration = duration;
	timer->started_at = 0;
	timer->expired = false;
	NAPC_MAGIC_INIT(napc__OSTimer, timer);
}
