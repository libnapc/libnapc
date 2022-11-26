#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_LINUX_GENERIC
	#include <libnapc-serial/_private/_libnapc-serial.h>

	void HAL_libnapc_initSerial(void) {
		PV_libnapc_serial_available = true;
	}
#endif
