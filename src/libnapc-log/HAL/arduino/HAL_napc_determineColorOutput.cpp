#if defined(ARDUINO)
	extern "C" {
		#include <libnapc-log/_private/_libnapc-log.h>

		// no-op on arduino
		void HAL_napc_determineColorOutput(void) {

		}
	}
#endif
