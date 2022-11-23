#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	#include <Arduino.h> // delay()

	extern "C" {
		#include <napc-delay/_private/_napc-delay.h>

		void HAL_libnapc_delay(napc_time amount) {
			delay(amount);
		}
	}
#endif