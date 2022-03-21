#if defined(ARDUINO)
	#include <Arduino.h> // delay()

	extern "C" {
		#include <napc-delay/_private/_napc-delay.h>

		void HAL_napc_delay(napc_time amount) {
			delay(amount);
		}
	}
#endif
