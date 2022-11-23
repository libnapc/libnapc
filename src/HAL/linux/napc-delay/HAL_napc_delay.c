#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <napc-delay/_private/_napc-delay.h>
	#include <unistd.h> // usleep()

	void HAL_napc_delay(napc_time amount) {
		usleep(amount * 1E3);
	}
#endif
