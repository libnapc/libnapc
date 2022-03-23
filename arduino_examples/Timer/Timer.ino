#include <napc.h>

napc__Timer my_timer;
int counter = 0;

void napc_app_setup(const char *platform) {
	// initialize timer (this does NOT start the timer)
	napc_Timer_init(&my_timer, 1000);

	// start the timer
	napc_Timer_start(&my_timer);
}

bool napc_app_loop(napc_time uptime) {
	if (napc_Timer_expired(&my_timer)) {
		++counter;

		if (counter >= 4) {
			napc_printf("4 Seconds have passed. Stopping program.");

			return false;
		}

		napc_printf("1 Second is over. Restarting timer now.\n");

		napc_Timer_restart(&my_timer);
	}

	return true;
}
