#if defined(ARDUINO)
	extern "C" {
		#include <napc-panic/_private/_napc-panic.h>

		void HAL_napc_abort(void) {
			while (true);
		}
	}
#endif
