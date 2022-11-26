#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	extern "C" {
		#include <libnapc-panic/_private/_libnapc-panic.h>

		void HAL_libnapc_abort(void) {
			while (true);
		}
	}
#endif
