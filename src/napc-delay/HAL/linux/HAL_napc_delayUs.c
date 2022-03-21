#if !defined(ARDUINO)
	#include <napc-delay/_private/_napc-delay.h>
	#include <unistd.h> // usleep()

	void HAL_napc_delayUs(napc_time amount) {
		usleep(amount);
	}
#endif
