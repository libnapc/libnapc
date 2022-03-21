#if defined(ARDUINO)
	#include <Arduino.h> // delayMicroseconds()

	extern "C" {
		#include <napc-delay/_private/_napc-delay.h>

		void HAL_napc_delayUs(napc_time amount) {
			delayMicroseconds(amount);
		}
	}
#endif
