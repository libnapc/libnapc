#if !defined(ARDUINO)
	#include <napc-serial/_private/_napc-serial.h>

	void HAL_napc_initSerial(void) {
		PV_napc_serial_available = true;
	}
#endif
