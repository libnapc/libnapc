#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>

	void HAL_napc_initFileSystem(void) {
		PV_napc_fs_initialized = true;
	}
#endif
