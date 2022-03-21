#if defined(ARDUINO)
	#include <Arduino.h> // Ax, pinMode()

	extern "C" {
		#include <napc-rand-source/_private/_napc-rand-source.h>

		void HAL_napc_initRandomBitSources(void) {
			pinMode(A0, INPUT);
			pinMode(A1, INPUT);
			pinMode(A2, INPUT);
			pinMode(A3, INPUT);
			pinMode(A4, INPUT);
			pinMode(A5, INPUT);
			pinMode(A6, INPUT);
		}
	}
#endif
