#if !defined(ARDUINO)
	#include <napc-core/_private/_napc-core.h>

	void HAL_napc_determineLoopYieldCPUDelay(void) {
		HAL_napc_loopYieldCPU(true);
	}
#endif
