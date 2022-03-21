#if !defined(ARDUINO)
	#include <napc-delay/_private/_napc-delay.h>
	#include <unistd.h> // usleep()

	void HAL_napc_delay(napc_time amount) {
		usleep(amount * 1E3);
	}
#endif
