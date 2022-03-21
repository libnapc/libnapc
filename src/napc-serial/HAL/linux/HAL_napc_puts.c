#if !defined(ARDUINO)
	#include <napc-serial/_private/_napc-serial.h>
	#include <stdio.h> // fprintf(), stderr

	void HAL_napc_puts(const char *str) {
		fprintf(stderr, "%s", str);
	}
#endif
