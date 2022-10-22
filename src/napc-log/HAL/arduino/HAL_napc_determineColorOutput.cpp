#if defined(ARDUINO)
	extern "C" {
		#include <napc-log/_private/_napc-log.h>

		// no-op on arduino
		void HAL_napc_determineColorOutput(void) {

		}
	}
#endif
