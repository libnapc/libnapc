#if defined(ARDUINO)
	extern "C" {
		#include <napc-core/_private/_napc-core.h>

		// no-op on arduino
		void HAL_napc_determineLoopYieldCPUDelay(void) {

		}
	}
#endif
