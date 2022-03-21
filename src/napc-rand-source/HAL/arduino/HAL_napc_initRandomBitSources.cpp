#if defined(ARDUINO)
	extern "C" {
		#include <napc-rand-source/_private/_napc-rand-source.h>

		// initialisation is done in getRandomBit.cpp
		bool PVHAL_arduino_napc_initRandom(void);

		void HAL_napc_initRandomBitSources(void) {
			PVHAL_arduino_napc_initRandom();
		}
	}
#endif
