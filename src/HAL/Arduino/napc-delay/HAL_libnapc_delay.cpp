#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	#include <Arduino.h> // delay()

	extern "C" {
		#include <libnapc-delay/_private/_libnapc-delay.h>

		void HAL_libnapc_delay(libnapc_time amount) {
			delay(amount);
		}
	}
#endif
