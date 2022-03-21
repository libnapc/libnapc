#if defined(ARDUINO)
	extern "C" {
		#include <napc-rand-source/_private/_napc-rand-source.h>

		static int _sources[9] = {0, 1, 2, 3, 4, 5, 6, 7, -1}; // @static

		const int *HAL_napc_getRandomBitSources(void) {
			return _sources;
		}
	}
#endif
