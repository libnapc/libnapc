#if defined(ARDUINO)
	#include <Arduino.h> // Serial

	extern "C" {
		#include <napc-serial/_private/_napc-serial.h>

		void HAL_napc_putc(char ch) {
			Serial.print(ch);
		}
	}
#endif
