#if defined(ARDUINO)
	#include <Arduino.h> // millis()

	extern "C" {
		#include <napc-time/_private/_napc_time.h>

		napc_time HAL_napc_getTimeSinceBoot(void) {
			return millis();
		}
	}
#endif
