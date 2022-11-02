#if defined(ARDUINO)
	extern "C" {
		#include <napc-core/_private/_napc-core.h>

		// no-op on arduino
		void HAL_napc_loopYieldCPU(bool dry_run) {
			NAPC_IGNORE_VALUE(dry_run);
		}
	}
#endif