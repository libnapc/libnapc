#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	#include <Arduino.h> // Serial

	extern "C" {
		#include <napc-serial/_private/_napc-serial.h>

		void HAL_napc_puts(const char *str) {
			Serial.print(str);
		}
	}
#endif
