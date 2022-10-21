#if defined(ARDUINO)
	#include <Arduino.h> // micros(), millis()

	extern "C" {
		#include <napc-time/_private/_napc_time.h>

		napc_time HAL_napc_getTimeSinceBoot(bool high_res) {
			if (high_res) {
				return micros();
			}

			return millis();
		}
	}
#endif
