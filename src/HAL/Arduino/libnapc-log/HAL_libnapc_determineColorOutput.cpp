#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	extern "C" {
		#include <libnapc-log/_private/_libnapc-log.h>

		// no-op on arduino
		void HAL_libnapc_determineColorOutput(void) {

		}
	}
#endif
