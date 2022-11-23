#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	extern "C" {
		#include <napc-panic/_private/_napc-panic.h>

		void HAL_napc_abort(void) {
			while (true);
		}
	}
#endif
