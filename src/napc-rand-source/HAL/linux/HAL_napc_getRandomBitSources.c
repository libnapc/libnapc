#if !defined(ARDUINO)
	#include <napc-rand-source/_private/_napc-rand-source.h>

	static int _sources[2] = {0, -1}; // @static

	const int *HAL_napc_getRandomBitSources(void) {
		return _sources;
	}
#endif
