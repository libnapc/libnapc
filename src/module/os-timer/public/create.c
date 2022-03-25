#include <module/os-timer/_private/_os-timer.h>

napc__OSTimer napc_OSTimer_create(napc_time duration) {
	napc__OSTimer timer;

	napc_OSTimer_init(&timer, duration);

	return timer;
}
