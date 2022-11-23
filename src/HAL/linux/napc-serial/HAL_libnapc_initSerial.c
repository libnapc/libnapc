#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <napc-serial/_private/_napc-serial.h>

	void HAL_libnapc_initSerial(void) {
		PV_napc_serial_available = true;
	}
#endif
