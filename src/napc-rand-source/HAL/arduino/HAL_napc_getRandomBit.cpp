#if defined(ARDUINO)
	extern "C" {
		#include <napc-rand-source/_private/_napc-rand-source.h>

		bool HAL_napc_getRandomBit(bool *out, int source) {
			return false;
		}
	}
#endif
