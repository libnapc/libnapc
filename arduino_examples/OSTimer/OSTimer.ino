#include <napc.h>

napc__OSTimer my_timer;
int counter = 0;

void napc_app_setup(const char *platform) {
	// initialize timer (this does NOT start the timer)
	napc_OSTimer_init(&my_timer, 1000);

	// start the single shot timer
	napc_OSTimer_start(&my_timer);
}

bool napc_app_loop(napc_time uptime) {
	// OSTimer only returns `true` once per expiration.
	if (napc_OSTimer_expired(&my_timer)) {
		++counter;

		if (counter >= 4) {
			napc_printf("4 Seconds have passed. Stopping program.");

			return false;
		}

		napc_printf("1 Second is over. Restarting timer now.\n");

		napc_OSTimer_restart(&my_timer);
	}

	return true;
}
