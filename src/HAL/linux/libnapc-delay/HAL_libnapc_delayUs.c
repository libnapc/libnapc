#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <libnapc-delay/_private/_libnapc-delay.h>
	#include <unistd.h> // usleep()

	void HAL_libnapc_delayUs(libnapc_time amount) {
		usleep(amount);
	}
#endif
