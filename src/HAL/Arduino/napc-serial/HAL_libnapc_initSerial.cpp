#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	#include <Arduino.h> // Serial

	extern "C" {
		#include <napc-serial/_private/_napc-serial.h>

		void HAL_libnapc_initSerial(void) {
			Serial.begin(9600);

			delay(3000);

			PV_libnapc_serial_available = !!Serial;
		}
	}
#endif
