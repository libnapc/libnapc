#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <libnapc-delay/_private/_libnapc-delay.h>
	#include <unistd.h> // usleep()

	void HAL_libnapc_delay(libnapc_time amount) {
		usleep(amount * 1E3);
	}
#endif
