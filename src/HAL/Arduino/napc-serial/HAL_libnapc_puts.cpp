#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	#include <Arduino.h> // Serial

	extern "C" {
		#include <libnapc-serial/_private/_libnapc-serial.h>

		void HAL_libnapc_puts(const char *str) {
			Serial.print(str);
		}
	}
#endif
