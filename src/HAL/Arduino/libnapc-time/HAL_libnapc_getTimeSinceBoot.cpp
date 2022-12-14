#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	#include <Arduino.h> // micros(), millis()

	extern "C" {
		#include <libnapc-time/_private/_libnapc_time.h>

		libnapc_time HAL_libnapc_getTimeSinceBoot(bool high_res) {
			if (high_res) {
				return micros();
			}

			return millis();
		}
	}
#endif
