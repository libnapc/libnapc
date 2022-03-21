#if defined(ARDUINO)
	#include <Arduino.h> // Serial

	extern "C" {
		#include <napc-serial/_private/_napc-serial.h>

		void HAL_napc_puts(const char *str) {
			Serial.print(str);
		}
	}
#endif
