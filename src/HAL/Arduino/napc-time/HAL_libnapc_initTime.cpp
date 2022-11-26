#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	extern "C" {
		#include <libnapc-time/_private/_libnapc_time.h>

		void HAL_libnapc_initTime(void) {

		}
	}
#endif
