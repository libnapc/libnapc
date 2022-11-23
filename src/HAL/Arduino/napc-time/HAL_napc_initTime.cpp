#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	extern "C" {
		#include <napc-time/_private/_napc_time.h>

		void HAL_napc_initTime(void) {

		}
	}
#endif
