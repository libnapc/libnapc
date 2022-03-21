#if !defined(ARDUINO)
	#include <napc-serial/_private/_napc-serial.h>
	#include <stdio.h> // fprintf(), stderr

	void HAL_napc_putc(char ch) {
		fprintf(stderr, "%c", ch);
	}
#endif
